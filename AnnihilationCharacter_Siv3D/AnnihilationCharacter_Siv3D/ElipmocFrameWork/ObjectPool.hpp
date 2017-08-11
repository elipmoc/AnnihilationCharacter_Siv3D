#pragma once
#include <vector>
#include <iterator>
#include <memory>
#include <type_traits>
#include "type_traits_original.hpp"
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


	template<bool ConstFlag,class SuperT,class ...SubsT >
	class ObjectPoolIterator;

	//�������v�[���R���e�i
	template<class SuperT,class ...SubsT>
	class ObjectPool {
		static_assert(variadic_is_all_base_of_v<SuperT,SubsT...>,"SuperT���p�����Ă��Ȃ�SubT������܂��I" );
		static_assert(variadic_is_distinct_v<SuperT, SubsT...>, "�d���������ڂ�����܂��I");
		const size_t m_maxSize;
		size_t m_nextIndex;
		size_t m_size;
		MemoryBlock<type_max_size_v<SuperT,SubsT...>>* m_storagePtr;
	public:
		//�C�e���[�^�̌^
		using Iterator = ObjectPoolIterator<false,SuperT,SubsT...>;
		using Const_Iterator = ObjectPoolIterator<true,SuperT,SubsT...>;

		ObjectPool(const size_t maxSize):m_maxSize(maxSize),m_size(0),m_nextIndex(0){
			m_storagePtr = new MemoryBlock<type_max_size_v<SuperT, SubsT...>>[m_maxSize];
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
		SuperT& operator[](size_t index)noexcept {
			return  *reinterpret_cast<SuperT*>(m_storagePtr[index].ptr.get());
		}
		const SuperT& operator[](size_t index)const noexcept {
			return  *reinterpret_cast<SuperT*>(m_storagePtr[index].ptr.get());
		}

		//�������m��
		template<class T=SuperT,class ...Args>
		T& New(Args&&... args) {
			static_assert(variadic_is_sames_v<T, SuperT, SubsT...>, "�����ł��Ȃ��^�ł�");
			if (m_nextIndex == m_maxSize)throw std::exception("�T�C�Y�������ς����您�����I�I");
			m_nextIndex++;
			m_size++;
			return *new(m_storagePtr[m_nextIndex - 1].ptr.get()) T(std::forward<Args>(args)...);
		}

		//placement New���Ȃ��Ń�������Object�Ƃ��ēn��
		SuperT& NoCallNew() {
			if (m_nextIndex == m_maxSize)throw std::exception("�T�C�Y�������ς����您�����I�I");
			m_nextIndex++;
			m_size++;
			return *reinterpret_cast<SuperT*>(m_storagePtr[m_nextIndex - 1].ptr.get());
		}

		//�����������[�X
		void DeleteAt(const size_t at) {
			(*this)[at].~SuperT();
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
				(*this)[i].~SuperT();
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
	template<bool ConstFlag,class SuperT,class ...SubsT>
	class ObjectPoolIterator :public std::iterator<std::random_access_iterator_tag, std::conditional_t<ConstFlag, const SuperT, SuperT>> {
	public:
		using ObjectType = std::conditional_t<ConstFlag, const SuperT, SuperT>;
		using ObjectPoolType = std::conditional_t<ConstFlag, const ObjectPool<SuperT,SubsT...>, ObjectPool<SuperT,SubsT...>>;
	private:
		friend ObjectPoolIterator<!ConstFlag,SuperT,SubsT...>;
		friend ObjectPool<SuperT,SubsT...>;
		ObjectPoolType& m_objectPool;
		size_t m_index;
		ObjectPoolIterator(ObjectPoolType& objectPool,const size_t index)
			:m_objectPool(objectPool),m_index(index){}

	public:
		using IteratorType = ObjectPoolIterator<ConstFlag,SuperT,SubsT...>;

		//�R�s�[�R���X�g���N�^
		ObjectPoolIterator(const ObjectPoolIterator<false,SuperT,SubsT...>& copyitr)
			:m_objectPool(copyitr.m_objectPool),m_index(copyitr.m_index) {}

		//�R�s�[�R���X�g���N�^
		template<class E=std::enable_if_t<ConstFlag>>
		ObjectPoolIterator(const ObjectPoolIterator<true,SuperT,SubsT...>& copyitr)
			:m_objectPool(copyitr.m_objectPool), m_index(copyitr.m_index) {}

		//�Q�Ɖ��Z�q
		const SuperT& operator*() const {
			return m_objectPool[m_index];
		}
		ObjectType& operator*() {
			return m_objectPool[m_index];
		}
		const SuperT& operator->() const {
			return m_objectPool[m_index];
		}
		ObjectType& operator->() {
			return m_objectPool[m_index];
		}
		const SuperT& operator[](int n) const {
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
	template<class F,class ...Types>
	void DeleteIf(ObjectPool<Types...>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.DeleteAt(i);
			else
				++i;
		}
	}
	template<class F,class ...Types>
	void NoCallDeleteIf(ObjectPool<Types...>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.NoCallDeleteAt(i);
			else
				++i;
		}
	}


	//begin�@end�̒�`

	template<class SuperT,class ...SubsT>
	inline typename ObjectPool<SuperT,SubsT...>::Iterator ObjectPool<SuperT,SubsT...>::begin()noexcept {
		return Iterator(*this, 0);
	}

	template<class SuperT, class ...SubsT>
	inline typename ObjectPool<SuperT, SubsT...>::Const_Iterator ObjectPool<SuperT, SubsT...>::begin()const noexcept {
		return Const_Iterator(*this, 0);
	}

	template<class SuperT, class ...SubsT>
	inline typename ObjectPool<SuperT, SubsT...>::Iterator ObjectPool<SuperT, SubsT...>::end()noexcept {
		return Iterator(*this, m_nextIndex);
	}

	template<class SuperT, class ...SubsT>
	inline typename ObjectPool<SuperT, SubsT...>::Const_Iterator ObjectPool<SuperT, SubsT...>::end()const noexcept {
		return Const_Iterator(*this, m_nextIndex);
	}

}