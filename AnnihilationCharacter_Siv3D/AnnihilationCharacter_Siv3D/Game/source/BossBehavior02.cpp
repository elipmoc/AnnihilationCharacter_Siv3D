#include "BossBehavior02.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	BossBehavior02::BossBehavior02(const BulletListCreator& bulletListCreator) :
		BossBehavior(bulletListCreator)
	{
	}
	void BossBehavior02::Update()
	{
		if (count % 20 == 0) {
			auto binfo=BulletInfo{ { 50 ,50 },{ 1,1 },{ 0,0 } };
			binfo.color = siv::Palette::Cadetblue;
			GetBulletListCreator().MakeBullet(binfo);
		}
		count++;
	}
}