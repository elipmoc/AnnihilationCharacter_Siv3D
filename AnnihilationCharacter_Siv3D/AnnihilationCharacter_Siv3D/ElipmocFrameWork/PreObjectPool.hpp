#pragma once
#include <iterator>
#include <memory>
#include <type_traits>
#include "ObjectPoolUtil.hpp"
#include "type_traits_original.hpp"

namespace elipmocframework {

	template<bool ConstFlag, class SuperT>
	class PreObjectPoolIterator;

	//�������v�[���R���e�i
	template<class SuperT>
	class PreObjectPool {
		const size_t m_maxSize;
		size_t m_nextIndex;
		size_t m_size;
		MemoryBlock<sizeof(SuperT)>* m_storagePtr;
	public:

		//�C�e���[�^�̌^
		using Iterator = PreObjectPoolIterator<false, SuperT>;
		using Const_Iterator = PreObjectPoolIterator<true, SuperT>;

		template<class...Args>
		PreObjectPool(const size_t maxSize,Args&& ...args) :m_maxSize(maxSize), m_size(0), m_nextIndex(0) {
			ObjectPoolCount::count++;
			m_storagePtr = new MemoryBlock<type_max_size_v<SuperT>>[m_maxSize];
			for (size_t i = 0; i < m_maxSize; i++) {
				*new(m_storagePtr[i].ptr.get()) SuperT(std::forward<Args>(args)...);
			}
		}

		~PreObjectPool() {
			ObjectPoolCount::count--;
			for (size_t i = 0; i<m_maxSize; i++)
				(*this)[i].~SuperT();
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


		//placement New���Ȃ��Ń�������Object�Ƃ��ēn��
		SuperT& NoCallNew() {
			if (m_nextIndex == m_maxSize)throw std::exception("�T�C�Y�������ς����您�����I�I");
			m_nextIndex++;
			m_size++;
			return *reinterpret_cast<SuperT*>(m_storagePtr[m_nextIndex - 1].ptr.get());
		}


		//�f�X�g���N�^���Ă΂Ȃ��Ń����������[�X
		void NoCallDeleteAt(const size_t at) {
			if (at >= m_size)throw std::exception("�͈͊O����ڂ����������I");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}

		//�f�X�g���N�^���Ă΂Ȃ��ł��ׂă����������[�X
		void NoCallDeleteAll() {
			m_size = 0;
			m_nextIndex = 0;
		}



	};

	//PreObjectPool�p�̎���C�e���[�^
	//ConstFlag�Ł@const_Iterator���������Ă�
	template<bool ConstFlag, class SuperT>
	class PreObjectPoolIterator :public std::iterator<std::random_access_iterator_tag, std::conditional_t<ConstFlag, const SuperT, SuperT>> {
	public:
		using PreObjectType = std::conditional_t<ConstFlag, const SuperT, SuperT>;
		using PreObjectPoolType = std::conditional_t<ConstFlag, const PreObjectPool<SuperT>, PreObjectPool<SuperT>>;
	private:
		friend PreObjectPoolIterator<!ConstFlag, SuperT>;
		friend PreObjectPool<SuperT>;
		PreObjectPoolType& m_objectPool;
		size_t m_index;
		PreObjectPoolIterator(PreObjectPoolType& objectPool, const size_t index)
			:m_objectPool(objectPool), m_index(index) {}

	public:
		using IteratorType = PreObjectPoolIterator<ConstFlag, SuperT>;

		//�R�s�[�R���X�g���N�^
		PreObjectPoolIterator(const PreObjectPoolIterator<false, SuperT>& copyitr)
			:m_objectPool(copyitr.m_objectPool), m_index(copyitr.m_index) {}

		//�R�s�[�R���X�g���N�^
		template<class E = std::enable_if_t<ConstFlag>>
		PreObjectPoolIterator(const PreObjectPoolIterator<true, SuperT>& copyitr)
			: m_objectPool(copyitr.m_objectPool), m_index(copyitr.m_index) {}

		//�Q�Ɖ��Z�q
		const SuperT& operator*() const {
			return m_objectPool[m_index];
		}
		PreObjectType& operator*() {
			return m_objectPool[m_index];
		}
		const SuperT& operator->() const {
			return m_objectPool[m_index];
		}
		PreObjectType& operator->() {
			return m_objectPool[m_index];
		}
		const SuperT& operator[](int n) const {
			return m_objectPool[m_index + n];
		};
		PreObjectType& operator[](int n) {
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
		bool operator==(const IteratorType& it) const noexcept {
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


	//begin�@end�̒�`

	template<class SuperT>
	inline typename PreObjectPool<SuperT>::Iterator PreObjectPool<SuperT>::begin()noexcept {
		return Iterator(*this, 0);
	}

	template<class SuperT>
	inline typename PreObjectPool<SuperT>::Const_Iterator PreObjectPool<SuperT>::begin()const noexcept {
		return Const_Iterator(*this, 0);
	}

	template<class SuperT>
	inline typename PreObjectPool<SuperT>::Iterator PreObjectPool<SuperT>::end()noexcept {
		return Iterator(*this, m_nextIndex);
	}

	template<class SuperT>
	inline typename PreObjectPool<SuperT>::Const_Iterator PreObjectPool<SuperT>::end()const noexcept {
		return Const_Iterator(*this, m_nextIndex);
	}

	template<class F, class Types>
	void NoCallDeleteIf(PreObjectPool<Types>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.NoCallDeleteAt(i);
			else
				++i;
		}
	}

}