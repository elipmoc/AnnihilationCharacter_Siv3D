#pragma once
#include <vector>
#include <iterator>
#include <memory>
#include <type_traits>
namespace elipmocframework {

	//�v�[���̍ŏ��P��
	template<size_t Size>
	struct MemoryBlock {
		//��������ۑ�����ꏊ
		std::unique_ptr<char[]> ptr = std::make_unique<char[]>(Size);

		MemoryBlock() = default;
		MemoryBlock(const MemoryBlock&) = delete;
		MemoryBlock(MemoryBlock&&) = delete;
		MemoryBlock& operator=(const MemoryBlock&) = delete;

		//��̃u���b�N�����ւ���
		void Swap(MemoryBlock&& m) {
			std::unique_ptr<char[]> temp = std::move(ptr);
			ptr = std::move(m.ptr);
			m.ptr = std::move(temp);
		}
	};

	template<class Object, bool ConstFlag>
	class ObjectPoolIterator;

	//�������v�[���R���e�i
	template<class Object>
	class ObjectPool {
		const size_t m_maxSize;
		size_t m_nextIndex;
		size_t m_size;
		MemoryBlock<sizeof(Object)>* m_storagePtr;
	public:
		//�C�e���[�^�̌^
		using Iterator = ObjectPoolIterator<Object, false>;
		using Const_Iterator = ObjectPoolIterator<Object,true>;

		ObjectPool(const size_t maxSize):m_maxSize(maxSize),m_size(0),m_nextIndex(0){
			m_storagePtr = new MemoryBlock<sizeof(Object)>[m_maxSize];
		}

		~ObjectPool() {
			delete[] m_storagePtr;
		}

		// �J�n�ʒu�������C�e���[�^���擾����B
		Iterator begin()noexcept;

		Const_Iterator begin()const noexcept;

		// �I���ʒu�������C�e���[�^���擾����B
		Iterator end()noexcept;

		Const_Iterator end()const noexcept;

		size_t Size()const noexcept { return m_size; }
		//�ő�T�C�Y
		size_t MaxSize()const noexcept { return m_maxSize; }

		//�Y�����ŃA�N�Z�X�ł���
		Object& operator[](size_t index)noexcept {
			return  *reinterpret_cast<Object*>(m_storagePtr[index].ptr.get());
		}
		const Object& operator[](size_t index)const noexcept {
			return  *reinterpret_cast<Object*>(m_storagePtr[index].ptr.get());
		}

		//�������m��
		template<class ...Args>
		Object& New(Args&&... args) {
			if (m_nextIndex == m_maxSize)throw std::exception("�T�C�Y�������ς����您�����I�I");
			m_nextIndex++;
			m_size++;
			return *new(m_storagePtr[m_nextIndex - 1].ptr.get()) Object(std::forward<Args>(args)...);
		}

		//placement New���Ȃ��Ń�������Object�Ƃ��ēn��
		Object& NoCallNew() {
			if (m_nextIndex == m_maxSize)throw std::exception("�T�C�Y�������ς����您�����I�I");
			m_nextIndex++;
			m_size++;
			return *reinterpret_cast<Object*>(m_storagePtr[m_nextIndex - 1].ptr.get());
		}

		//�����������[�X
		void DeleteAt(const size_t at) {
			(*this)[at].~Object();
			if (at >= m_size)throw std::exception("�͈͊O����ڂ����������I");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}

		//�f�X�g���N�^���Ă΂Ȃ��Ń����������[�X
		void NoCallDeleteAt(const size_t at) {
			if (at >= m_size)throw std::exception("�͈͊O����ڂ����������I");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}
		//���ׂă����������[�X
		void DeleteAll() {
			for(size_t i=0;i<m_size;i++)
				(*this)[i].~Object();
			m_size = 0;
			m_nextIndex = 0;
		}

		//�f�X�g���N�^���Ă΂Ȃ��ł��ׂă����������[�X
		void NoCallDeleteAll() {
			m_size = 0;
			m_nextIndex = 0;
		}
	};

	//ObjectPool�p�̎���C�e���[�^
	//ConstFlag�Ł@const_Iterator���������Ă�
	template<class Object,bool ConstFlag>
	class ObjectPoolIterator :public std::iterator<std::random_access_iterator_tag, std::conditional_t<ConstFlag, const Object, Object>> {
	public:
		using ObjectType = std::conditional_t<ConstFlag, const Object, Object>;
		using ObjectPoolType = std::conditional_t<ConstFlag, const ObjectPool<Object>, ObjectPool<Object>>;
	private:
		friend ObjectPoolIterator<Object, !ConstFlag>;
		friend ObjectPool<Object>;
		ObjectPoolType& m_objectPool;
		size_t m_index;
		ObjectPoolIterator(ObjectPoolType& objectPool,const size_t index)
			:m_objectPool(objectPool),m_index(index){}

	public:
		using IteratorType = ObjectPoolIterator<Object,ConstFlag>;

		//�R�s�[�R���X�g���N�^
		ObjectPoolIterator(const ObjectPoolIterator<Object,false>& copyitr)
			:m_objectPool(copyitr.m_objectPool),m_index(copyitr.m_index) {}

		//�R�s�[�R���X�g���N�^
		template<class E=std::enable_if_t<ConstFlag>>
		ObjectPoolIterator(const ObjectPoolIterator<Object, true>& copyitr)
			:m_objectPool(copyitr.m_objectPool), m_index(copyitr.m_index) {}

		//�Q�Ɖ��Z�q
		const Object& operator*() const {
			return m_objectPool[m_index];
		}
		ObjectType& operator*() {
			return m_objectPool[m_index];
		}
		const Object& operator->() const {
			return m_objectPool[m_index];
		}
		ObjectType& operator->() {
			return m_objectPool[m_index];
		}
		const Object& operator[](int n) const {
			return m_objectPool[m_index + n];
		};
		ObjectType& operator[](int n) {
			return m_objectPool[m_index + n];
		}
		//�ړ��n���Z�q
		IteratorType operator+(size_t n)const noexcept {
			return IteratorType(m_objectPool, m_index + n);
		}
		iterator& operator+=(size_t n) noexcept {
			m_index += n;
			return *this;
		}
		iterator& operator++() noexcept {
			++m_index;
			return *this;
		}
		iterator operator++(int) noexcept {
			return IteratorType(m_objectPool, m_index++);
		}

		IteratorType operator-(size_t n)const noexcept {
			return IteratorType(m_objectPool, m_index - n);
		}
		iterator& operator-=(size_t n) noexcept {
			m_index -= n;
			return *this;
		}
		iterator& operator--() noexcept {
			--m_index;
			return *this;
		}
		iterator operator--(int)noexcept {
			return IteratorType(m_objectPool, m_index--);
		}
		//��r���Z�q
		bool operator==(const IteratorType& it) const noexcept{
			return (it.m_index == m_index && &it.m_objectPool == &m_objectPool);
		}
		bool operator!=(const IteratorType& it) const noexcept {
			return !((*this) == it);
		}
		bool operator>(const IteratorType& it) const noexcept {
			return (m_index > it.m_index);
		}
		bool operator<(const IteratorType& it) const noexcept {
			return (m_index < it.m_index);
		}
		bool operator>=(const IteratorType& it) const noexcept {
			return (m_index >= it.m_index);
		}
		bool operator<=(const IteratorType& it) const noexcept {
			return (m_index <= it.m_index);
		}
	};

	//���[�e�B���e�B�I��

	//�����ɍ��������폜
	template<class Object,class F>
	void DeleteIf(ObjectPool<Object>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.DeleteAt(i);
			else
				++i;
		}
	}
	template<class Object, class F>
	void NoCallDeleteIf(ObjectPool<Object>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.NoCallDeleteAt(i);
			else
				++i;
		}
	}


	//begin�@end�̒�`

	template<class Object>
	inline typename ObjectPool<Object>::Iterator ObjectPool<Object>::begin()noexcept {
		return Iterator(*this, 0);
	}

	template<class Object>
	inline typename ObjectPool<Object>::Const_Iterator ObjectPool<Object>::begin()const noexcept {
		return Const_Iterator(*this, 0);
	}

	template<class Object>
	inline typename ObjectPool<Object>::Iterator ObjectPool<Object>::end()noexcept {
		return Iterator(*this, m_nextIndex);
	}

	template<class Object>
	inline typename ObjectPool<Object>::Const_Iterator ObjectPool<Object>::end()const noexcept {
		return Const_Iterator(*this, m_nextIndex);
	}

}