#include "EnemyBarrage\HomingShot.hpp"
#include "BulletList.hpp"

void game::HomingShot::NormalUpdate() {
	if (count++ == 0) {
		siv::Vec2 addPos = (GetPlayerPos() - GetPos()) / GetPos().distanceFrom(GetPlayerPos());
		GetBulletList().MakeBullet(GetPos(), addPos*6, { 0,0 });
	}
}

void game::HomingShot::RengokuUpdate(){
	if (count%25== 0 && count <=25*3) {
		siv::Vec2 addPos = (GetPlayerPos() - GetPos()) / GetPos().distanceFrom(GetPlayerPos());
		GetBulletList().MakeBullet(GetPos(), addPos * 6, { 0,0 });
	}
	count++;
}