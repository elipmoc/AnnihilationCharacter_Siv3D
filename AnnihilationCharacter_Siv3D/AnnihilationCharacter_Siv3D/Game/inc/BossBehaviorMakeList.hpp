#pragma once
#include <array>

namespace game {

	class BossBehaviorMakeBase;

	class BossBehaviorMakeList {
		std::array<std::unique_ptr<BossBehaviorMakeBase>, 2> list;
		//Ÿ‚ÉNext‚Å“n‚·list‚Ì—v‘f”‚ğ•Û‘¶‚·‚é
		size_t index=0;
	public:
		BossBehaviorMakeList();
		~BossBehaviorMakeList();
		std::unique_ptr<BossBehaviorMakeBase> Next();

	};

}