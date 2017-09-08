#include "EnemyBarrage\HorizontalShot3Way.hpp"
#include "BulletList.hpp"

namespace  game {
	void HorizontalShot3Way::Update()
	{
		if (count++ == 0) {
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			GetBulletList().MakeBullet(GetPos(), { -3 * siv::Math::Cos(siv::Math::Radians(30)),-3 * siv::Math::Sin(siv::Math::Radians(30)) }, { 0,0 });
			GetBulletList().MakeBullet(GetPos(), { -3*siv::Math::Cos(siv::Math::Radians(-30)),-3* siv::Math::Sin(siv::Math::Radians(-30)) }, { 0,0 });
		}
		GetBulletList().Update();
	}
}
