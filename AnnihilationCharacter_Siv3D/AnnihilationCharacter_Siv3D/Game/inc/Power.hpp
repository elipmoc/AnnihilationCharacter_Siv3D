#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"

namespace game {

	class CollisionCircle;

	//力の文字
	class Power :public elipmocframework::FontObject, public elipmocframework::has_delete_flag {

		//速度ベクトル
		siv::Vec2 m_speedv;

		//あたり判定
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