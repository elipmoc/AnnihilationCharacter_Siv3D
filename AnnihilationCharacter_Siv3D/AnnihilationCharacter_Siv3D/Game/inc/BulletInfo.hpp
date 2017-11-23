#pragma once
#include "CollisionCircle.hpp"

namespace game {

	class Bullet;

	//�e�쐬�Ɏg�p������
	struct BulletInfo
	{
		//�e�ʒu
		siv::Vec2 pos = {0,0};
		//�e���x
		siv::Vec2 speed = {0,0};
		//�e�����x
		siv::Vec2 vspeed = {0,0};
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
		//�e�̓����蔻��ID
		CollisionID colliID=CollisionID::EnemyBulletID;
		//�e�̃t�H���g�傫��
		size_t fontSize = 17;

		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
		BulletInfo() = default;
	};

}