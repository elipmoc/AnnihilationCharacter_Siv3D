#pragma once
#include "BossBehavior.hpp"

namespace game {
	class BossBehavior01 :public BossBehavior {
		int count = 0;
	public:
		BossBehavior01(const BulletListCreator&);
		virtual void Update()override final;
	};
}