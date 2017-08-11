#pragma once
#include "FontObject.hpp"
namespace game {
	class Bullet :public elipmocframework::FontObject {
		//���x�x�N�g��
		siv::Vec2 m_speedv;
		//�����x�x�N�g��
		siv::Vec2 m_vspeedv;
		//�폜�t���O
		bool deleteFlag = false;
	public:

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv) 
			:elipmocframework::FontObject(L"�e",20), m_speedv(speedv), m_vspeedv(vspeedv) 
		{
			SetPos(pos);
		}

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