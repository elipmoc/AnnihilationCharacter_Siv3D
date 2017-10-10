#include "EnemyBarrage\HorizontalShotOne.hpp"
#include "BulletList.hpp"

namespace  game {

	void HorizontalShotOne::YawarakaUpdate() {
		if (count++ == 0) {
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
	}

	void HorizontalShotOne::NormalUpdate()
	{
		if (count == 0 || count == 20) {
			GetBulletList().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}

	void HorizontalShotOne::RengokuUpdate()
	{
		if (count == 0 || count == 15 || count==30) {
			GetBulletList().MakeBullet(GetPos(), { -3.5,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}
}
