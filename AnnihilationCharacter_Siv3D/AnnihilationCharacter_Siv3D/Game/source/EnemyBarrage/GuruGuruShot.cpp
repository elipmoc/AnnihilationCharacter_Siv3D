#include "EnemyBarrage\GuruGuruShot.hpp"
#include "BulletListCreator.hpp"

namespace game {
	using siv::Math::Sin;
	using siv::Math::Cos;
	using siv::Math::Radians;


	void GuruGuruShot::YawarakaUpdate() {
		if (count % 15 == 0 && count < 60 * 4) {
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				GetBulletListCreator().MakeBullet(GetPos(), tmp * 2, -tmp*0.04);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

	void GuruGuruShot::NormalUpdate()
	{
		if (count % 15 == 0 && count < 60 * 4) {
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				siv::Vec2 tmp2 = { Cos(angle + Radians(i + 10)),Sin(angle + Radians(i + 10)) };
				GetBulletListCreator().MakeBullet(GetPos(), tmp * 2, -tmp*0.04);
				GetBulletListCreator().MakeBullet(GetPos(), tmp2 * 2, -tmp2*0.04);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

	void GuruGuruShot::RengokuUpdate()
	{
		if (count % 10 == 0 && count < 60 * 4) {
			for (int i = 0; i < 360; i += 90) {
				siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
				siv::Vec2 tmp2 = { Cos(angle + Radians(i + 10)),Sin(angle + Radians(i + 10)) };
				GetBulletListCreator().MakeBullet(GetPos(), tmp * 2, -tmp*0.04);
				GetBulletListCreator().MakeBullet(GetPos(), tmp2 * 2, -tmp2*0.04);
			}
			siv::SoundAsset(L"shot").playMulti();
			angle += Radians(20);
		}
		count++;
	}

}