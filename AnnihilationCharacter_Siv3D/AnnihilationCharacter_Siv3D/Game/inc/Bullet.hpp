#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {

	class CollisionCircle;
	enum class CollisionID;

	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//���x�x�N�g��
		siv::Vec2 m_speedv;
		//�����x�x�N�g��
		siv::Vec2 m_vspeedv;
		//�J�E���^�[
		size_t m_counter=0;
		//�����蔻��
		std::unique_ptr<CollisionCircle> m_colli;

		using func_type = void(*)(Bullet&);
		func_type m_func=nullptr;

	public:

		void Delete() {
			delete_flag = true;
		}

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv,const CollisionID&);
		~Bullet();

		void SetFunc(func_type func) {
			m_func = func;
		}

		virtual void Update()override;

	};
}