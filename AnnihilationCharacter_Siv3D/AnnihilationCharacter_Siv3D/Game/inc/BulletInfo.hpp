#pragma once
#include "CollisionCircle.hpp"

namespace game {

	class Bullet;

	//弾作成に使用する情報
	struct BulletInfo
	{
		//弾位置
		siv::Vec2 pos = {0,0};
		//弾速度
		siv::Vec2 speed = {0,0};
		//弾加速度
		siv::Vec2 vspeed = {0,0};
		//継続してかかり続ける力
		siv::Vec2 continuationForce = {0,0};
		//瞬間にかかる力
		siv::Vec2 momentForce = { 0,0 };
		//空気抵抗係数
		double k=0;
		//弾色
		siv::Color color=siv::Palette::White;
		//ブラー
		int32 blur = 10;
		//ガンマ
		double gamma = 2.0;
		//光らせる色
		siv::Color glowColor = siv::Palette::White;
		//光らせるかどうかのフラグ
		bool glowFlag = false;
		//埋め込む関数
		void(*func)(Bullet&)=nullptr;
		//弾の当たり判定ID
		CollisionID colliID=CollisionID::EnemyBulletID;
		//弾のフォント大きさ
		size_t fontSize = 17;

		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
		BulletInfo() = default;
	};

}