#include "EnemyBarrage\HorizontalShotOnes.hpp"
#include "BulletListCreator.hpp"

namespace  game {

	void HorizontalShotOnes::YawarakaUpdate() {
		if (count % 50 == 0) {
			GetBulletListCreator().MakeBullet(GetPos(), { -3,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}

	void HorizontalShotOnes::NormalUpdate()
	{
		if (count % 40 == 0) {
			GetBulletListCreator().MakeBullet(GetPos(), { -3.2,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}

	void HorizontalShotOnes::RengokuUpdate()
	{
		if (count % 30 == 0) {
			GetBulletListCreator().MakeBullet(GetPos(), { -4.2,0 }, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}
}
