#pragma once
#include <memory>

namespace elipmocframework{
	class GlowText;
}

namespace game {

	class CollisionCircle;
	class Barrier {
		//バリア有効時間
		static constexpr size_t ENABLE_TIME = 230;
		//バリア有効時間カウント
		size_t count=ENABLE_TIME;
		//壁の数
		static constexpr size_t WALL_NUM = 8;
		//壁の距離
		static constexpr int DISTANCE = 40;
		//壁のずらす座標
		siv::Vec2 m_offsetpos[WALL_NUM];
		//追従用主人公の座標
		const siv::Vec2& bind_playerPos;
		//あたり判定object
		std::unique_ptr<CollisionCircle> m_colliObject;

		std::unique_ptr<elipmocframework::GlowText>walls[WALL_NUM];
	public:
		Barrier(const siv::Vec2& playerPos);
		~Barrier();
		void SetBarrier();
		bool IsBarrier() {
			return count != ENABLE_TIME;
		}
		void Draw()const;
		void Update();
	};

}