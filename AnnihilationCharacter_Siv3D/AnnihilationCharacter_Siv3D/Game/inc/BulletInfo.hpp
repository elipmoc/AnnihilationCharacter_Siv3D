#pragma once

namespace game {

	//’eì¬‚ÉŽg—p‚·‚éî•ñ
	struct BulletInfo
	{
		//’eˆÊ’u
		siv::Vec2 pos;
		//’e‘¬“x
		siv::Vec2 speed;
		//’e‰Á‘¬“x
		siv::Vec2 vspeed;
		//’eF
		siv::Color color=siv::Palette::White;


		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
	};

}