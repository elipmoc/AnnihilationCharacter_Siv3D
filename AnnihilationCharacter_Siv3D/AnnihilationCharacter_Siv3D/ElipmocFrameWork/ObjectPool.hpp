#pragma once
#include <vector>
#include <iterator>
#include <memory>
#include <type_traits>
#include "type_traits_original.hpp"
namespace elipmocframework {

	//プールの最小単位
	template<size_t Size>
	struct MemoryBlock {
		//メモリを保存する場所
		std::unique_ptr<char[]> ptr = std::make_unique<char[]>(Size);

		MemoryBlock() = default;
		MemoryBlock(const MemoryBlock&) = delete;
		MemoryBlock(MemoryBlock&&) = delete;
		MemoryBlock& operator=(const MemoryBlock&) = delete;

		//二つのブロックを入れ替える
		void Swap(MemoryBlock&& m) {
			std::unique_ptr<char[]> temp = std::move(ptr);
			ptr = std::move(m.ptr);
			m.ptr = std::move(temp);
		}
	};


	template<bool ConstFlag,class SuperT,class ...SubsT >
	class ObjectPoolIterator;

	//メモリプールコンテナ
	template<class SuperT,class ...SubsT>
	class ObjectPool {
		static_assert(variadic_is_all_base_of_v<SuperT,SubsT...>,"SuperTを継承していないSubTがあります！" );
		static_assert(variadic_is_distinct_v<SuperT, SubsT...>, "重複した項目があります！");
		const size_t m_maxSize;
		size_t m_nextIndex;
		size_t m_size;
		MemoryBlock<type_max_size_v<SuperT,SubsT...>>* m_storagePtr;
	public:
		//イテレータの型
		using Iterator = ObjectPoolIterator<false,SuperT,SubsT...>;
		using Const_Iterator = ObjectPoolIterator<true,SuperT,SubsT...>;

		ObjectPool(const size_t maxSize):m_maxSize(maxSize),m_size(0),m_nextIndex(0){
			m_storagePtr = new MemoryBlock<type_max_size_v<SuperT, SubsT...>>[m_maxSize];
		}

		~ObjectPool() {
			delete[] m_storagePtr;
		}

		// 開始位置を示すイテレータを取得する。
		Iterator begin()noexcept;

		Const_Iterator begin()const noexcept;

		// 終了位置を示すイテレータを取得する。
		Iterator end()noexcept;

		Const_Iterator end()const noexcept;

		size_t Size()const noexcept { return m_size; }
		//最大サイズ
		size_t MaxSize()const noexcept { return m_maxSize; }

		//添え字でアクセスできる
		SuperT& operator[](size_t index)noexcept {
			return  *reinterpret_cast<SuperT*>(m_storagePtr[index].ptr.get());
		}
		const SuperT& operator[](size_t index)const noexcept {
			return  *reinterpret_cast<SuperT*>(m_storagePtr[index].ptr.get());
		}

		//メモリ確保
		template<class T=SuperT,class ...Args>
		T& New(Args&&... args) {
			static_assert(variadic_is_sames_v<T, SuperT, SubsT...>, "生成できない型です");
			if (m_nextIndex == m_maxSize)throw std::exception("サイズがいっぱいだよおおお！！");
			m_nextIndex++;
			m_size++;
			return *new(m_storagePtr[m_nextIndex - 1].ptr.get()) T(std::forward<Args>(args)...);
		}

		//placement NewしないでメモリをObjectとして渡す
		SuperT& NoCallNew() {
			if (m_nextIndex == m_maxSize)throw std::exception("サイズがいっぱいだよおおお！！");
			m_nextIndex++;
			m_size++;
			return *reinterpret_cast<SuperT*>(m_storagePtr[m_nextIndex - 1].ptr.get());
		}

		//メモリリリース
		void DeleteAt(const size_t at) {
			(*this)[at].~SuperT();
			if (at >= m_size)throw std::exception("範囲外じゃぼけええええ！");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}

		//デストラクタを呼ばないでメモリリリース
		void NoCallDeleteAt(const size_t at) {
			if (at >= m_size)throw std::exception("範囲外じゃぼけええええ！");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}
		//すべてメモリリリース
		void DeleteAll() {
			for(size_t i=0;i<m_size;i++)
				(*this)[i].~SuperT();
			m_size = 0;
			m_nextIndex = 0;
		}

		//デストラクタを呼ばないですべてメモリリリース
		void NoCallDeleteAll() {
			m_size = 0;
			m_nextIndex = 0;
		}
	};

	//ObjectPool用の自作イテレータ
	//ConstFlagで　const_Iteratorを実現してる
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

		//コピーコンストラクタ
		ObjectPoolIterator(const ObjectPoolIterator<false,SuperT,SubsT...>& copyitr)
			:m_objectPool(copyitr.m_objectPool),m_index(copyitr.m_index) {}

		//コピーコンストラクタ
		template<class E=std::enable_if_t<ConstFlag>>
		ObjectPoolIterator(const ObjectPoolIterator<true,SuperT,SubsT...>& copyitr)
			:m_objectPool(copyitr.m_objectPool), m_index(copyitr.m_index) {}

		//参照演算子
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
		//移動系演算子
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
		//比較演算子
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

	//ユーティリティ的な

	//条件に合う物を削除
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


	//begin　endの定義

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