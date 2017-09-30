#include "EnemyBarrage\GuruGuruShot.hpp"
#include "BulletList.hpp"

using siv::Math::Sin;
using siv::Math::Cos;
using siv::Math::Radians;

void game::GuruGuruShot::NormalUpdate()
{
	if (count % 15 == 0 && count <60*4) {
		for (int i = 0; i < 360; i += 90) {
			siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
			GetBulletList().MakeBullet(GetPos(), tmp*2, -tmp*0.04);
		}
		siv::SoundAsset(L"shot").playMulti();
		angle += Radians(20);
	}
	count++;
}

void game::GuruGuruShot::RengokuUpdate()
{
	if (count % 15 == 0 && count <60 * 4) {
		for (int i = 0; i < 360; i += 90) {
			siv::Vec2 tmp = { Cos(angle + Radians(i)),Sin(angle + Radians(i)) };
			siv::Vec2 tmp2 = { Cos(angle + Radians(i+10)),Sin(angle + Radians(i+10)) };
			GetBulletList().MakeBullet(GetPos(), tmp * 2, -tmp*0.04);
			GetBulletList().MakeBullet(GetPos(), tmp2 * 2, -tmp2*0.04);
		}
		siv::SoundAsset(L"shot").playMulti();
		angle += Radians(20);
	}
	count++;
}
