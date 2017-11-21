#pragma once

namespace game {

	class Bullet;

	//弾作成に使用する情報
	struct BulletInfo
	{
		//弾位置
		siv::Vec2 pos;
		//弾速度
		siv::Vec2 speed;
		//弾加速度
		siv::Vec2 vspeed;
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


		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
	};

}