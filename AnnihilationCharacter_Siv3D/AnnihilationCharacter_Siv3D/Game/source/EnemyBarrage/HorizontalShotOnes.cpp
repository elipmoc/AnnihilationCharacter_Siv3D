#include "EnemyBarrage\HorizontalShotOnes.hpp"
#include "BulletList.hpp"

namespace  game {
	void HorizontalShotOnes::Update()
	{
		if (count%50 == 0)
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
		count++;
		GetBulletList().Update();
	}
}
