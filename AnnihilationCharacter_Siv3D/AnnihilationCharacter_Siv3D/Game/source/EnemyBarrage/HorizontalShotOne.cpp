#include "EnemyBarrage\HorizontalShotOne.hpp"
#include "BulletList.hpp"

namespace  game {
	void HorizontalShotOne::NormalUpdate()
	{
		if (count++ == 0) {
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
	}
	void HorizontalShotOne::RengokuUpdate()
	{
		if (count == 0 || count == 20) {
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}
}
