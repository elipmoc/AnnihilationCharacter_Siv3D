#include "BossBehavior02.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"
#include "Bullet.hpp"
#include "Boss.hpp"

namespace game {
	using siv::Math::Sin;
	using siv::Math::Cos;

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
		if (count%240 == 0) {
			BulletInfo binfo;
			binfo.pos = Boss::BOSS_POS;
			binfo.color = siv::Palette::Cadetblue;
			binfo.func = [](Bullet& bullet) {
				if (bullet.GetCounter() == 80) {
					double angle = (siv::Random(0, 180) + 90) / 180.0 * siv::Math::Pi;
					bullet.SetSpeed({ Cos(angle) * 2,Sin(angle) * 2 });
					bullet.ReSetCounter();
				}
			};
			for (size_t i = 0; i < 10; i++) {
				double angle = (siv::Random(0, 180)+90) / 180.0 * siv::Math::Pi;
				binfo.speed = { Cos(angle)*4,Sin(angle)*4 };
				binfo.k = 0.02;
				GetBulletListCreator().MakeBullet(binfo);
			}
		}
		count++;
	}

}