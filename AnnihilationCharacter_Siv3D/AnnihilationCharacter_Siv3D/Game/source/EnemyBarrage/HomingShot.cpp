#include "EnemyBarrage\HomingShot.hpp"
#include "BulletList.hpp"

namespace game {

	void HomingShot::YawarakaUpdate() {
		if (count++ == 0) {
			siv::Vec2 addPos = (GetPlayerPos() - GetPos()) / GetPos().distanceFrom(GetPlayerPos());
			GetBulletList().MakeBullet(GetPos(), addPos * 6, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
	}

	void HomingShot::NormalUpdate() {
		if (count % 25 == 0 && count <= 25 * 3) {
			siv::Vec2 addPos = (GetPlayerPos() - GetPos()) / GetPos().distanceFrom(GetPlayerPos());
			GetBulletList().MakeBullet(GetPos(), addPos * 6, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}

	void HomingShot::RengokuUpdate() {
		using siv::Math::Radians;
		using siv::Math::Cos;
		using siv::Math::Sin;
		if (count % 25 == 0 && count <= 25 * 3) {
			double angle = siv::Random(0, 359);
			siv::Vec2 addPos = (GetPlayerPos() - GetPos()) / GetPos().distanceFrom(GetPlayerPos());
			GetBulletList().MakeBullet(GetPos(), addPos * 6, { 0,0 });
			GetBulletList().MakeBullet(GetPos(), { 4.5*Cos(angle),4.5*Sin(angle) }, { 0,0 });
			angle = siv::Random(0, 359);
			GetBulletList().MakeBullet(GetPos(), {4.5*Cos(angle),4.5*Sin(angle)}, { 0,0 });
			siv::SoundAsset(L"shot").playMulti();
		}
		count++;
	}
}