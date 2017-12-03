#pragma once
#include "CollisionCircle.hpp"

namespace game {

	class Bullet;

	//’eì¬‚ÉŽg—p‚·‚éî•ñ
	struct BulletInfo
	{
		//’eˆÊ’u
		siv::Vec2 pos = {0,0};
		//’e‘¬“x
		siv::Vec2 speed = {0,0};
		//’e‰Á‘¬“x
		siv::Vec2 vspeed = {0,0};
		//Œp‘±‚µ‚Ä‚©‚©‚è‘±‚¯‚é—Í
		siv::Vec2 continuationForce = {0,0};
		//uŠÔ‚É‚©‚©‚é—Í
		siv::Vec2 momentForce = { 0,0 };
		//‹ó‹C’ïRŒW”
		double k=0;
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
		//’e‚ÌƒtƒHƒ“ƒg‘å‚«‚³
		size_t fontSize = 17;

		BulletInfo(const siv::Vec2& pos, const siv::Vec2& speed, const siv::Vec2& vspeed) {
			this->pos = pos;
			this->speed = speed;
			this->vspeed = vspeed;
		}
		BulletInfo() = default;
	};

}