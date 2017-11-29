#include "BossBehavior02.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	BossBehavior02::BossBehavior02(const Level level,const siv::Vec2& playerRefPos, const BulletListCreator& bulletListCreator) :
		BossBehavior(level, playerRefPos,bulletListCreator)
	{
	}
	void BossBehavior02::YawarakaUpdate()
	{
		if (count % 20 == 0) {
			auto binfo = BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } };
			binfo.color = siv::Palette::Cadetblue;
			GetBulletListCreator().MakeBullet(binfo);
		}
		count++;
	}
	void BossBehavior02::NormalUpdate()
	{
		if (count % 20 == 0) {
			auto binfo = BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } };
			binfo.color = siv::Palette::Cadetblue;
			GetBulletListCreator().MakeBullet(binfo);
		}
		count++;
	}
	void BossBehavior02::RengokuUpdate()
	{
		if (count % 20 == 0) {
			auto binfo = BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } };
			binfo.color = siv::Palette::Cadetblue;
			GetBulletListCreator().MakeBullet(binfo);
		}
		count++;
	}

}