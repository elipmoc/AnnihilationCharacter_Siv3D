#pragma once
#include <memory>
#include "FontObject.hpp"
#include"Interface.hpp"
namespace game {

	class CollisionCircle;
	enum class CollisionID;

	class Bullet :public elipmocframework::FontObject,public elipmocframework::has_delete_flag {
		//速度ベクトル
		siv::Vec2 m_speed;
		//加速度ベクトル
		siv::Vec2 m_vspeed;
		//空気抵抗係数
		double m_k;
		//瞬間にかかる力
		siv::Vec2 m_momentForce = {0,0};
		//継続してかかり続ける力
		siv::Vec2 m_continuationForce;
		//カウンター
		size_t m_counter=0;
		//あたり判定
		std::unique_ptr<CollisionCircle> m_colli;

		using func_type = void(*)(Bullet&);
		func_type m_func=nullptr;

	public:

		Bullet& SetmomentForce(const siv::Vec2& momentForce) { m_momentForce = momentForce; return *this; };
		siv::Vec2 GetmomentForce()const noexcept { return m_momentForce; }

		Bullet& SetcontinuationForce(const siv::Vec2& continuationForce) { m_continuationForce = continuationForce; return *this; };
		siv::Vec2 GetcontinuationForce()const noexcept { return m_continuationForce; }

		//空気抵抗係数のゲッタセッター
		Bullet& SetK(double k) { m_k = k; return *this; }
		double GetK() { return m_k; }

		Bullet& SetSpeed(const siv::Vec2& speed) { m_speed = speed; return *this; };
		siv::Vec2 GetSpeed()const noexcept { return m_speed; }

		Bullet& SetVspeed(const siv::Vec2& vspeed) { m_vspeed = vspeed; return *this; };
		siv::Vec2 GetVspeed()const noexcept { return m_vspeed; }

		size_t GetCounter() { return m_counter; }
		void ReSetCounter() { m_counter = 0; }

		void Delete() {
			delete_flag = true;
		}

		Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv,const CollisionID&,size_t fontSize);
		~Bullet();

		void SetFunc(func_type func) {
			m_func = func;
		}

		virtual void Update()override;

	};
}