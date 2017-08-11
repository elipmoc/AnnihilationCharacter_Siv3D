#pragma once
#include "FontObject.hpp"
namespace game {
	class Bullet :public elipmocframework::FontObject {
		//速度ベクトル
		siv::Vec2 m_speedv;
		//加速度ベクトル
		siv::Vec2 m_vspeedv;
	public:

		Bullet() :elipmocframework::FontObject(L"弾",20){}

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