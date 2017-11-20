#pragma once

namespace game {

	//�e�쐬�Ɏg�p������
	struct BulletInfo
	{
		//�e�ʒu
		siv::Vec2 pos;
		//�e���x
		siv::Vec2 speed;
		//�e�����x
		siv::Vec2 vspeed;
		//�e�F
		siv::Color color=siv::Palette::White;


		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
	};

}