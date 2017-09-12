#pragma once
#include <memory>

namespace elipmocframework{
	class GlowText;
}

namespace game {

	class CollisionCircle;
	class Barrier {
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
		void Draw()const;
		void Update();
	};

}