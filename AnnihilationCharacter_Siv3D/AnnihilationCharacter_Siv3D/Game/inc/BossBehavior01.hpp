#pragma once
#include "BossBehavior.hpp"

namespace game {
	class BossBehavior01 :public BossBehavior {
		int count = 0;
	public:
		BossBehavior01(const Level,const siv::Vec2&,const BulletListCreator&);
		virtual void YawarakaUpdate() override final;
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate() override final;
	};
}