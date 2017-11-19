#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {

	class CollisionCircle;

	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//速度ベクトル
		siv::Vec2 m_speedv;
		//加速度ベクトル
		siv::Vec2 m_vspeedv;

		//あたり判定
		std::unique_ptr<CollisionCircle> m_colli;

		using func_type = void(*)(Bullet&);
		func_type m_func=nullptr;

	public:

		void Delete() {
			delete_flag = true;
		}

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv);
		~Bullet();

		void SetFunc(func_type func) {
			m_func = func;
		}

		virtual void Update()override;

	};
}