#include "BossBehaviorWait.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"
#include "Boss.hpp"

namespace game {
	BossBehaviorWait::BossBehaviorWait(const Level level, const siv::Vec2 & playerRefPos, const BulletListCreator & bulletListCreator)
		:BossBehavior(level,playerRefPos,bulletListCreator)
	{
	}
	void BossBehaviorWait::YawarakaUpdate()
	{
	}
	void BossBehaviorWait::NormalUpdate()
	{
	}
	void BossBehaviorWait::RengokuUpdate()
	{
	}
}