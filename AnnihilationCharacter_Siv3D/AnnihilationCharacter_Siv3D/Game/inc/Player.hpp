#pragma once
#include "FontObject.hpp"
#include <memory>

namespace elipmocframework {
	class ParticleList;
}

namespace game {

	class Barrier;
	class TerrainControl;
	class CollisionCircle;
	class Player :public elipmocframework::FontObject {
		//無敵時間
		static constexpr int MUTEKI_TIME = 150;

		//無敵時間カウント
		int m_mutekiCount=0;

		//死亡時のパーティクル
		std::unique_ptr<elipmocframework::ParticleList> m_deadParticle;

		//あたり判定object
		std::unique_ptr<CollisionCircle> m_colliObject;

		//バリア
		std::unique_ptr<Barrier> m_barrier;

		//hp
		size_t m_hp=6;

		//バリア展開回数
		size_t m_barrierCount=3;

		//移動スピード
		static constexpr double m_speed=4.3;
		//重力加速度
		static constexpr double m_g=0.3;
		//Yの速度
		double m_yv=0;
		//ジャンプした回数記録
		int m_jumpCount=0;
		//デバック用
		siv::Circle circle;		

		//自分の足元にある地形レーン
		int m_underLane = 2;

		//移動アクション
		void Move(const std::unique_ptr<TerrainControl>&);

		//主人公死亡処理
		void PlayerDead();

		//主人公落下死亡処理
		void PlayerFallDead();

		//主人公の足元のYを得る
		double GetUnderY()const {
			return GetPos().y + 15;
		}


		//主人公のXをセットする
		void SetPosX(double x) {
			SetPos({ x,GetPos().y });
		}

		//主人公の足元の高さをセットする
		void SetUnderY(double y) {
			SetPos({ GetPos().x,y - 15 });
		}

	public:

		size_t GetHp()const noexcept { return m_hp; }
		size_t GetBarrierCount()const noexcept { return m_barrierCount; }
		Player();
		~Player();



		void Update2(const std::unique_ptr<TerrainControl>&);
	};

}