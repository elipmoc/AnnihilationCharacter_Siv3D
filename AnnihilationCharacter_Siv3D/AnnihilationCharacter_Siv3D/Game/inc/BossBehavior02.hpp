#pragma once
#include "BossBehavior.hpp"

namespace game {
	class BossBehavior02 :public BossBehavior {
		int count = 0;
	public:
		BossBehavior02(const BulletListCreator&);
		virtual void Update()override final;
	};
}