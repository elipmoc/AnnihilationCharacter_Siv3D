#pragma once
#include <vector>
#include <iterator>
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

	template<class Object>
	class ObjectPoolIterator;

	//メモリプールコンテナ
	template<class Object>
	class ObjectPool {
		const size_t m_maxSize;
		size_t m_nextIndex;
		size_t m_size;
		MemoryBlock<sizeof(Object)>* m_storagePtr;
	public:
		//イテレータの型
		using Iterator = ObjectPoolIterator<Object>;

		ObjectPool(const size_t maxSize):m_maxSize(maxSize),m_size(0),m_nextIndex(0){
			m_storagePtr = new MemoryBlock<sizeof(Object)>[m_maxSize];
		}

		~ObjectPool() {
			delete[] m_storagePtr;
		}

		// 開始位置を示すイテレータを取得する。
		Iterator begin()noexcept;

		// 終了位置を示すイテレータを取得する。
		Iterator end()noexcept;

		size_t Size()const noexcept { return m_size; }

		//添え字でアクセスできる
		Object& operator[](size_t index)noexcept {
			return  *reinterpret_cast<Object*>(m_storagePtr[index].ptr.get());
		}
		const Object& operator[](size_t index)const noexcept {
			return  *reinterpret_cast<Object*>(m_storagePtr[index].ptr.get());
		}

		//メモリ確保
		template<class ...Args>
		Object& New(Args&&... args) {
			if (m_nextIndex == m_maxSize)throw std::exception("サイズがいっぱいだよおおお！！");
			m_nextIndex++;
			m_size++;
			return *new(m_storagePtr[m_nextIndex - 1].ptr.get()) Object(std::forward<Args>(args)...);
		}

		//メモリリリース
		void DeleteAt(const size_t at) {
			(*this)[at].~Object();
			if (at >= m_size)throw std::exception("範囲外じゃぼけええええ！");
			if (at != m_size - 1)
				m_storagePtr[at].Swap(std::move(m_storagePtr[m_size - 1]));
			m_size--;
			m_nextIndex--;
		}
	};

	//ObjectPool用の自作イテレータ
	template<class Object>
	class ObjectPoolIterator :public std::iterator<std::random_access_iterator_tag,Object> {
		friend ObjectPool<Object>;
		ObjectPool<Object>& m_objectPool;
		size_t m_index;
		ObjectPoolIterator(ObjectPool<Object>& objectPool,const size_t index)
			:m_objectPool(objectPool),m_index(index){}

	public:
		using IteratorType = ObjectPoolIterator<Object>;

		//コピーコンストラクタ
		ObjectPoolIterator(const ObjectPoolIterator<Object>& copyitr)
			:m_objectPool(copyitr.m_objectPool),m_index(copyitr.m_index) {}

		//参照演算子
		const Object& operator*() const {
			return m_objectPool[m_index];
		}
		Object& operator*() {
			return m_objectPool[m_index];
		}
		const Object& operator->() const {
			return m_objectPool[m_index];
		}
		Object& operator->() {
			return m_objectPool[m_index];
		}
		const Object& operator[](int n) const {
			return m_objectPool[m_index + n];
		};
		Object& operator[](int n) {
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
	//条件に合う物を削除
	template<class Object,class F>
	void DeleteIf(ObjectPool<Object>& objectPool, F&& pred) {
		for (size_t i = 0; i < objectPool.Size();) {
			if (pred(objectPool[i]))
				objectPool.DeleteAt(i);
			else
				++i;
		}
	}


	template<class Object>
	inline typename ObjectPool<Object>::Iterator ObjectPool<Object>::begin()noexcept {
		return Iterator(*this, 0);
	}

	template<class Object>
	inline typename ObjectPool<Object>::Iterator ObjectPool<Object>::end()noexcept {
		return Iterator(*this, m_nextIndex);
	}

}