#include "EnemyBarrage\UpShot.hpp"
#include "BulletList.hpp"

void game::UpShot::NormalUpdate()
{
	if (count%50== 0)
		GetBulletList().MakeBullet(GetPos(), { 0,-3 }, { 0,0 });
	count++;
}

void game::UpShot::RengokuUpdate()
{
	using siv::Math::Radians;
	using siv::Math::Cos;
	using siv::Math::Sin;
	if (count%50== 0) {
		GetBulletList().MakeBullet(GetPos(), { 0,-3.2 }, { 0,0 });
		double angle = siv::Random(-30, 30);
		GetBulletList().MakeBullet(GetPos(), { -2*Cos(Radians(90 + angle)),-2*Sin(Radians(90 + angle)) }, { 0,0 });
		GetBulletList().MakeBullet(GetPos(), { -2*Cos(Radians(90-angle)),-2*Sin(Radians(90-angle)) }, { 0,0 });

	}
	count++;
}
