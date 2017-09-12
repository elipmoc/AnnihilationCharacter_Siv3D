#pragma once
#include <memory>

namespace elipmocframework{
	class GlowText;
}

namespace game {

	class CollisionCircle;
	class Barrier {
		//�ǂ̐�
		static constexpr size_t WALL_NUM = 8;
		//�ǂ̋���
		static constexpr int DISTANCE = 40;
		//�ǂ̂��炷���W
		siv::Vec2 m_offsetpos[WALL_NUM];
		//�Ǐ]�p��l���̍��W
		const siv::Vec2& bind_playerPos;
		//�����蔻��object
		std::unique_ptr<CollisionCircle> m_colliObject;

		std::unique_ptr<elipmocframework::GlowText>walls[WALL_NUM];
	public:
		Barrier(const siv::Vec2& playerPos);
		~Barrier();
		void Draw()const;
		void Update();
	};

}