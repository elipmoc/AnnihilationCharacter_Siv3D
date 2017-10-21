#pragma once
#include "BossBehavior.hpp"

namespace game {
	class BossBehavior01:public BossBehavior {
	public:
		BossBehavior01(const BulletListCreator&);
		virtual void Update()override final;
	};
}