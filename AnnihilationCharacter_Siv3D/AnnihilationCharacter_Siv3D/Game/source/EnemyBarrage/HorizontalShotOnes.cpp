#include "EnemyBarrage\HorizontalShotOnes.hpp"
#include "BulletList.hpp"

namespace  game {
	void HorizontalShotOnes::NormalUpdate()
	{
		if (count%50 == 0)
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
		count++;
	}
	void HorizontalShotOnes::RengokuUpdate()
	{
		if (count % 40 == 0)
			GetBulletList().MakeBullet(GetPos(), { -3.2,0 }, { 0,0 });
		count++;
	}
}
