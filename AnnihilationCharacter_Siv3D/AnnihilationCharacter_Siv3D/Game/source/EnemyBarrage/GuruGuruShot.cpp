#include "EnemyBarrage\GuruGuruShot.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	using siv::Math::Sin;
	using siv::Math::Cos;
	using siv::Math::Radians;


	void GuruGuruShot::YawarakaUpdate() {
		if (count % 15 == 0 && count < 60 * 4) {
			BulletInfo binfo;
			binfo.pos = GetPos();
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				binfo.speed = tmp * 2;
				binfo.continuationForce = -tmp*0.04;
				GetBulletListCreator().MakeBullet(binfo);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

	void GuruGuruShot::NormalUpdate()
	{

		if (count % 15 == 0 && count < 60 * 4) {
			BulletInfo binfo;
			binfo.pos = GetPos();
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				siv::Vec2 tmp2 = { Cos(angle + Radians(i + 10)),Sin(angle + Radians(i + 10)) };
				binfo.speed = tmp * 2;
				binfo.continuationForce = -tmp*0.04;
				GetBulletListCreator().MakeBullet(binfo);
				binfo.speed = tmp2 * 2;
				binfo.continuationForce = -tmp2*0.04;
				GetBulletListCreator().MakeBullet(binfo);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

	void GuruGuruShot::RengokuUpdate()
	{
		if (count % 10 == 0 && count < 60 * 4) {
			BulletInfo binfo;
			binfo.pos = GetPos();
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				siv::Vec2 tmp2 = { Cos(angle + Radians(i + 10)),Sin(angle + Radians(i + 10)) };
				binfo.speed = tmp * 2;
				binfo.continuationForce = -tmp*0.04;
				GetBulletListCreator().MakeBullet(binfo);
				binfo.speed = tmp2 * 2;
				binfo.continuationForce = -tmp2*0.04;
				GetBulletListCreator().MakeBullet(binfo);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

}