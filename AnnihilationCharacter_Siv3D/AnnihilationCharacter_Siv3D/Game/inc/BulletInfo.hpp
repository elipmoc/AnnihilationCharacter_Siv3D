#pragma once

namespace game {

	class Bullet;

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
		//�u���[
		int32 blur = 10;
		//�K���}
		double gamma = 2.0;
		//���点��F
		siv::Color glowColor = siv::Palette::White;
		//���点�邩�ǂ����̃t���O
		bool glowFlag = false;
		//���ߍ��ފ֐�
		void(*func)(Bullet&)=nullptr;


		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
	};

}