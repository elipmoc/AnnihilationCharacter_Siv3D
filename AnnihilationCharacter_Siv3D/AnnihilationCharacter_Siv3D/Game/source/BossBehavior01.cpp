#include "BossBehavior01.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	BossBehavior01::BossBehavior01(const Level level,const siv::Vec2& playerRefPos,const BulletListCreator& bulletListCreator):
		BossBehavior(level,playerRefPos,bulletListCreator)
	{
	}
	void BossBehavior01::YawarakaUpdate()
	{
		if (count % 20 == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } });
		}
		count++;
	}
	void BossBehavior01::NormalUpdate()
	{
		if (count % 20 == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } });
		}
		count++;
	}
	void BossBehavior01::RengokuUpdate()
	{
		if (count % 20 == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } });
		}
		count++;
	}
}