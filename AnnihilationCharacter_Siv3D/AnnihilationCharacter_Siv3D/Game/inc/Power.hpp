#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"

namespace game {

	class CollisionCircle;

	//�͂̕���
	class Power :public elipmocframework::FontObject, public elipmocframework::has_delete_flag {

		//���x�x�N�g��
		siv::Vec2 m_speedv;

		//�����蔻��
		std::unique_ptr<CollisionCircle> m_colli;

	public:

		void Delete() {
			delete_flag = true;
		}

		Power(Power&&);
		Power(const siv::Vec2 & pos, const siv::Vec2 & speedv);
		~Power();

		virtual void Update()override;

	};

}