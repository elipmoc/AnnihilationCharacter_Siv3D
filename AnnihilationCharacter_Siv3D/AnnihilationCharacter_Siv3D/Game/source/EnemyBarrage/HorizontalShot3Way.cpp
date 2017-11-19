#include "EnemyBarrage\HorizontalShot3Way.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"


namespace  game {

	void HorizontalShot3Way::YawarakaUpdate() {
		if (count++ == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3,0 }, { 0,0 } });
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3 * siv::Math::Cos(siv::Math::Radians(30)),-3 * siv::Math::Sin(siv::Math::Radians(30)) }, { 0,0 } });
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3 * siv::Math::Cos(siv::Math::Radians(-30)),-3 * siv::Math::Sin(siv::Math::Radians(-30)) }, { 0,0 } });
			siv::SoundAsset(L"shot").playMulti();
		}
	}

	void HorizontalShot3Way::NormalUpdate()
	{
		if (count++ == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3.5,0 }, { 0,0 }});
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3.5 * siv::Math::Cos(siv::Math::Radians(30)),-3.5 * siv::Math::Sin(siv::Math::Radians(30)) }, { 0,0 } });
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -3.5 * siv::Math::Cos(siv::Math::Radians(-30)),-3.5 * siv::Math::Sin(siv::Math::Radians(-30)) }, { 0,0 } });
			siv::SoundAsset(L"shot").playMulti();
		}
	}
	void HorizontalShot3Way::RengokuUpdate()
	{
		if (count++ == 0) {
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -4.5,0 }, { 0,0 } });
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -4.5 * siv::Math::Cos(siv::Math::Radians(30)),-4.5 * siv::Math::Sin(siv::Math::Radians(30)) }, { 0,0 } });
			GetBulletListCreator().MakeBullet(BulletInfo{ GetPos(), { -4.5 * siv::Math::Cos(siv::Math::Radians(-30)),-4.5 * siv::Math::Sin(siv::Math::Radians(-30)) }, { 0,0 } });
			siv::SoundAsset(L"shot").playMulti();
		}
	}
}
