#pragma once

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

	class ObjectPoolCount {
	public:
		static int count;
	};
}