#pragma once
#include <memory>

namespace elipmocframework{
	class GlowText;
}

namespace game {

	class Barrier {
		static constexpr size_t WALL_NUM = 8;
		static constexpr int DISTANCE = 40;
		siv::Vec2 m_offsetpos[WALL_NUM];
		const siv::Vec2& bind_playerPos;
		std::unique_ptr<elipmocframework::GlowText>walls[WALL_NUM];
	public:
		Barrier(const siv::Vec2& playerPos);
		~Barrier();
		void Draw()const;
		void Update();
	};

}