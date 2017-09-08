#include "EnemyBarrage\HorizontalShotOne.hpp"
#include "BulletList.hpp"

namespace  game {
	void HorizontalShotOne::Update()
	{
		if(count++==0)
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
		GetBulletList().Update();
	}
}
