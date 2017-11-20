#include "BossBehavior01.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	BossBehavior01::BossBehavior01(const BulletListCreator& bulletListCreator):
		BossBehavior(bulletListCreator)
	{
	}
	void BossBehavior01::Update()
	{
		if (count % 20 == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ { 50 ,50 }, { 1,1 }, { 0,0 }});
		}
		count++;
	}
}