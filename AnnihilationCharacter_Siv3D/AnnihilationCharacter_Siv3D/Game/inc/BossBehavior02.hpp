#pragma once
#include "BossBehavior.hpp"

namespace game {
	class BossBehavior02 :public BossBehavior {
		int count = 0;
	public:
		BossBehavior02(const Level, const BulletListCreator&);
		virtual void YawarakaUpdate() override final;
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate() override final;
	};
}