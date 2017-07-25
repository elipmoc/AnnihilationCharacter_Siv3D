#pragma once
#include <functional>

namespace game {

	//コリジョン識別番号
	enum class CollisionID {
		EnemyID,
		EnemyBulletID,
		PlayerID,
		ItemID
	};
	//円のあたり判定
	class CollisionCircle {

		const siv::Vec2& bind_pos;
		//半径
		double m_r;
		//ずらす座標
		siv::Vec2 m_offsetPos;

		CollisionID m_collisionID;
		//衝突したときに呼ばれる関数
		const std::function<void(CollisionID)> m_hitFunc;
	public:
		CollisionID GetCollisionID()const { return m_collisionID; }
		void SetCollisionID(const CollisionID collisionID){ m_collisionID=collisionID; }

		siv::Vec2 GetPos()const { return bind_pos; }

		siv::Vec2 GetOffsetPos()const { return m_offsetPos; }
		void SetOffsetPos(const siv::Vec2& offsetPos){ m_offsetPos=offsetPos; }

		double GetR()const { return m_r; }
		void SetR(const double r) { m_r = r; }

		void HitCheck(CollisionCircle& cc) {
			const auto&& temp= ((bind_pos + m_offsetPos) - (cc.bind_pos + cc.m_offsetPos));
			if ((temp.x*temp.x + temp.y*temp.y) <= (m_r + cc.m_r)*(m_r + cc.m_r)) {
				//衝突してる時の処理
				if (m_hitFunc)m_hitFunc(cc.m_collisionID);
				if (cc.m_hitFunc)cc.m_hitFunc(m_collisionID);
			}
		}

		//座標と関数をバインドする
		template<class F>
		CollisionCircle(const siv::Vec2& pos,F func):bind_pos(pos),m_hitFunc(func){}

	};
}