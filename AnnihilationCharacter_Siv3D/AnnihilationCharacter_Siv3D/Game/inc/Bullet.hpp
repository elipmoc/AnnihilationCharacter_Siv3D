#pragma once
#include "FontObject.hpp"
namespace game {
	class Bullet :public elipmocframework::FontObject {
		//���x�x�N�g��
		siv::Vec2 m_speedv;
		//�����x�x�N�g��
		siv::Vec2 m_vspeedv;
	public:

		Bullet() :elipmocframework::FontObject(L"�e",20){}

		virtual void Update()override{
			elipmocframework::FontObject::Update();
			SetPos(GetPos() + m_speedv);
			m_speedv += m_vspeedv;
		}
	};

	//�֐��������邱�ƂŁA�Ǝ��̓��������������悤�Ɋg��������
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