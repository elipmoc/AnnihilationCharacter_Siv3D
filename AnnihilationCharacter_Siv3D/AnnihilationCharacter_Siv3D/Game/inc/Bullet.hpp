#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {

	class CollisionCircle;
	enum class CollisionID;

	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//���x�x�N�g��
		siv::Vec2 m_speed;
		//�����x�x�N�g��
		siv::Vec2 m_vspeed;
		//�J�E���^�[
		size_t m_counter=0;
		//�����蔻��
		std::unique_ptr<CollisionCircle> m_colli;

		using func_type = void(*)(Bullet&);
		func_type m_func=nullptr;

	public:

		Bullet& SetSpeed(const siv::Vec2& speed) { m_speed = speed; return *this; };
		siv::Vec2 GetSpeed()const noexcept { return m_speed; }

		Bullet& SetVspeed(const siv::Vec2& vspeed) { m_vspeed = vspeed; return *this; };
		siv::Vec2 GetVspeed()const noexcept { return m_vspeed; }

		size_t GetCounter() { return m_counter; }

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