#pragma once

namespace game {

	//弾作成に使用する情報
	struct BulletInfo
	{
		//弾位置
		siv::Vec2 pos;
		//弾速度
		siv::Vec2 speed;
		//弾加速度
		siv::Vec2 vspeed;
	};

}