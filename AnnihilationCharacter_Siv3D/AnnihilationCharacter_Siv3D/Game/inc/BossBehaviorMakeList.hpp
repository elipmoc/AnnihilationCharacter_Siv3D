#pragma once
#include <array>

namespace game {

	class BossBehaviorMakeBase;

	class BossBehaviorMakeList {
		std::array<std::unique_ptr<BossBehaviorMakeBase>, 2> list;
		//次にNextで渡すlistの要素数を保存する
		size_t index=0;
	public:
		BossBehaviorMakeList();
		~BossBehaviorMakeList();
		std::unique_ptr<BossBehaviorMakeBase> Next();

	};

}