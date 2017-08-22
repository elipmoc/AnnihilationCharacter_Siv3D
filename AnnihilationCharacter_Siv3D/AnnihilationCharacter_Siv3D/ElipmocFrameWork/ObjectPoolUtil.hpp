#pragma once

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

	class ObjectPoolCount {
	public:
		static int count;
	};
}