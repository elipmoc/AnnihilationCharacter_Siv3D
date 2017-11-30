#include "BossBehavior01.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"
#include "Boss.hpp"

namespace game {
	BossBehavior01::BossBehavior01(const Level level,const siv::Vec2& playerRefPos,const BulletListCreator& bulletListCreator):
		BossBehavior(level,playerRefPos,bulletListCreator)
	{
	}
	void BossBehavior01::YawarakaUpdate()
	{
		if (count % 30 == 0) {
			const auto addPos=(GetPlayerPos() - siv::Vec2{50,50})/ siv::Vec2{ 50,50 }.distanceFrom(GetPlayerPos());
			GetBulletListCreator().MakeBullet(BulletInfo{ { 50 ,50 },addPos,{ 0,0 } });
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
		switch (count2)
		{
		case 0:
		{
			BulletInfo bInfos[2];
			bInfos[0] = BulletInfo{ Boss::BOSS_POS + siv::Vec2{ -10,-20 },{ -3,0 },{ 0,0 } };
			bInfos[1] = BulletInfo{ Boss::BOSS_POS + siv::Vec2{-10,100},{ -3,0 },{ 0,0 } };
			for (int j = 0; j < 2; j++) {
				GetBulletListCreator().MakeBullet(bInfos[j]);
				for (int i = 1; i < 3; i++) {
					for (int e = -1; e < 2; e += 2) {
						double angle = e*i * 10 / 180.0*siv::Math::Pi;
						bInfos[j].speed = siv::Vec2{ -siv::Math::Cos(angle),siv::Math::Sin(angle) }*3;
						GetBulletListCreator().MakeBullet(bInfos[j]);
					}
				}
			}
			count2++;
		}
			break;
		case 1:
			if (count>120 && count % 30 == 0 && count < 120+30 * 5) {
				auto bInfo = BulletInfo{ Boss::BOSS_POS + siv::Vec2{ -10,50 },{ -3,0 },{ 0,0 } };
				GetBulletListCreator().MakeBullet(bInfo);
				for (int i = 1; i < 5; i++) {
					for (int e = -1; e < 2; e += 2) {
						double angle = e*i * 8 / 180.0*siv::Math::Pi;
						bInfo.speed = siv::Vec2{ -siv::Math::Cos(angle),siv::Math::Sin(angle) }*3;
						GetBulletListCreator().MakeBullet(bInfo);
					}
				}
			}
			else if (count >= 120 + 30 * 5+120) {
				count2 = 0;
				count = 0;
			}
			break;
		}
		count++;
	}
}