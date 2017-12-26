#pragma once
#include <array>

namespace game {

	class BossBehaviorMakeBase;

	class BossBehaviorMakeList {
		std::array<std::unique_ptr<BossBehaviorMakeBase>, 3> list;
		//Ÿ‚ÉNext‚Å“n‚·list‚Ì—v‘f”‚ğ•Û‘¶‚·‚é
		size_t index=0;
	public:
		size_t GetSize() const noexcept{ return list.size(); }
		BossBehaviorMakeList();
		~BossBehaviorMakeList();
		std::unique_ptr<BossBehaviorMakeBase> Next();

	};

}