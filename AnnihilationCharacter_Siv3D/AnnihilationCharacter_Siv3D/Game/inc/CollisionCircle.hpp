#pragma once
#include <functional>
#include "Interface.hpp"

namespace game {

	//コリジョン識別番号
	enum class CollisionID {
		EnemyID,
		EnemyBulletID,
		PlayerID,
		BarrierID,
		PowerID,
		PowerBlastID
	};

	class CollisionCircle;
	struct CollisionData:public elipmocframework::has_delete_flag {
		const CollisionCircle& m_collision;
		
		CollisionData(const CollisionCircle& collision) noexcept:m_collision(collision) {

		}
		//あたり判定有効かどうか
		bool IsEnable()const noexcept{ return m_enableFlag; }
		//あたり判定有効化する
		void Enable()noexcept { m_enableFlag = true; };
		//あたり判定無効化する
		void Disable()noexcept { m_enableFlag = false; };
		//削除要求をだす
		void EnableDelete() noexcept{ delete_flag = true; }
	private:
		//あたり判定有効フラグ
		bool m_enableFlag = true;
	};

	//円のあたり判定
	class CollisionCircle {

		CollisionData& m_colliData;

		const siv::Vec2& bind_pos;
		//半径
		double m_r;
		//ずらす座標
		siv::Vec2 m_offsetPos;

		//衝突キュー
		mutable siv::Array<CollisionID> m_colliQueue;

		CollisionID m_collisionID;
		//衝突したときに呼ばれる関数
		const std::function<void(CollisionID)> m_hitFunc;
		//CollisionControlに登録する
		void RegisterCollision();
	public:
		CollisionID GetCollisionID()const noexcept{ return m_collisionID; }
		void SetCollisionID(const CollisionID collisionID)noexcept{ m_collisionID=collisionID; }

		siv::Vec2 GetBindPos()const noexcept{ return bind_pos; }

		siv::Vec2 GetPos()const noexcept{ return bind_pos+m_offsetPos; }

		siv::Vec2 GetOffsetPos()const noexcept{ return m_offsetPos; }
		void SetOffsetPos(const siv::Vec2& offsetPos) noexcept{ m_offsetPos=offsetPos; }

		double GetR()const noexcept{ return m_r; }
		void SetR(const double r) noexcept{ m_r = r; }

		//あたり判定有効かどうか
		bool IsEnable()const noexcept { return m_colliData.IsEnable(); }
		//あたり判定有効化する
		void Enable()noexcept { m_colliData.Enable(); };
		//あたり判定無効化する
		void Disable()noexcept { m_colliData.Disable(); };

		//あたり判定計算
		void HitCheck(const CollisionCircle& cc)const {
			const auto&& temp= ((bind_pos + m_offsetPos) - (cc.bind_pos + cc.m_offsetPos));
			if ((temp.x*temp.x + temp.y*temp.y) <= (m_r + cc.m_r)*(m_r + cc.m_r)) {
				m_colliQueue.push_back(cc.m_collisionID);
				cc.m_colliQueue.push_back(m_collisionID);
			}
		}


		//衝突処理を実行
		void DoColliQueue() {
			for (const auto& id : m_colliQueue) {
				m_hitFunc(id);
			}
			m_colliQueue.clear();
		}

		//座標と関数をバインドする
		template<class F>
		CollisionCircle(const siv::Vec2& pos,F func)
			:bind_pos(pos),m_hitFunc(func),m_colliData(*(new CollisionData(*this))){
			RegisterCollision();
		}

		//デバッグ描画
		void DebugDraw() const{
			siv::Circle(GetPos(), m_r).draw({255,0,0,150});
		}

		//デストラクタ
		~CollisionCircle() noexcept{
			m_colliData.EnableDelete();
		}

	};



}