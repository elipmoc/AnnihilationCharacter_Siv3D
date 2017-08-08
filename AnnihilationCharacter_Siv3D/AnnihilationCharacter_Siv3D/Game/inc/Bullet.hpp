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
	template<class Func>
	class BulletEX :public Bullet {
		const Func m_func;
	public:

		BulletEX(const Func& func) {
			m_func=func
		}

		virtual void Update()override {
			Bullet::Update();
			func(*this);
		}
	};
}