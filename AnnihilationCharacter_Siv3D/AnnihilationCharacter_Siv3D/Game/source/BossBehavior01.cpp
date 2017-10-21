#include "BossBehavior01.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossBehavior01::BossBehavior01(const BulletListCreator& bulletListCreator):
		BossBehavior(bulletListCreator)
	{
	}
	void BossBehavior01::Update()
	{
		GetBulletListCreator().MakeBullet({ 50 ,50 }, { 1,1 }, { 0,0 });
	}
}