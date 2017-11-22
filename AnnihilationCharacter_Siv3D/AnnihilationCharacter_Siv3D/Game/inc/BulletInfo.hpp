#pragma once
#include "CollisionCircle.hpp"

namespace game {

	class Bullet;

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
		//ƒuƒ‰[
		int32 blur = 10;
		//ƒKƒ“ƒ}
		double gamma = 2.0;
		//Œõ‚ç‚¹‚éF
		siv::Color glowColor = siv::Palette::White;
		//Œõ‚ç‚¹‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
		bool glowFlag = false;
		//–„‚ßž‚ÞŠÖ”
		void(*func)(Bullet&)=nullptr;
		//’e‚Ì“–‚½‚è”»’èID
		CollisionID colliID=CollisionID::EnemyBulletID;

		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
	};

}