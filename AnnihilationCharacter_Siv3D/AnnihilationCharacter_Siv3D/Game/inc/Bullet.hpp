#pragma once
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {
	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//速度ベクトル
		siv::Vec2 m_speedv;
		//加速度ベクトル
		siv::Vec2 m_vspeedv;
	public:

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv) 
			:elipmocframework::FontObject(L"弾",20), m_speedv(speedv), m_vspeedv(vspeedv) 
		{
			SetPos(pos);
		}

		virtual void Update()override{
			elipmocframework::FontObject::Update();
			SetPos(GetPos() + m_speedv);
			m_speedv += m_vspeedv;
		}
	};

	//関数を代入することで、独自の動作を持たせられるように拡張した版
	class BulletEX :public Bullet {
		using func_type=void(*)(Bullet&);
		func_type m_func;
	public:

		template<class Func>
		BulletEX(const Func& func) {
			m_func = func;
		}

		virtual void Update()override {
			Bullet::Update();
			m_func(*this);
		}
	};
}