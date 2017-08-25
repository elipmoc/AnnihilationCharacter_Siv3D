#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {

	class CollisionCircle;

	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//���x�x�N�g��
		siv::Vec2 m_speedv;
		//�����x�x�N�g��
		siv::Vec2 m_vspeedv;

		//�����蔻��
		std::unique_ptr<CollisionCircle> m_colli;

	public:

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv);
		~Bullet();

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