#include "Barrier.hpp"
#include "ElipmocFrameWork\GlowText.hpp"
#include "CollisionCircle.hpp"

namespace game {
	Barrier::Barrier(const siv::Vec2 & playerPos)
		:bind_playerPos(playerPos),
		m_colliObject(
			std::make_unique<CollisionCircle>(bind_playerPos, [this](CollisionID){})
		)
	{
		m_colliObject->SetCollisionID(CollisionID::BarrierID);
		m_colliObject->SetR(60);
		m_offsetpos[0] = { DISTANCE,0 };
		m_offsetpos[1] = { DISTANCE,DISTANCE };
		m_offsetpos[2] = { 0,DISTANCE };
		m_offsetpos[3] = { -DISTANCE,DISTANCE };
		m_offsetpos[4] = { -DISTANCE,0 };
		m_offsetpos[5] = { -DISTANCE,-DISTANCE };
		m_offsetpos[6] = { 0,-DISTANCE };
		m_offsetpos[7] = { DISTANCE,-DISTANCE };
		for (size_t i = 0; i < WALL_NUM; i++) {
			walls[i] = std::make_unique<elipmocframework::GlowText>(siv::Font(),L"•Ç",40);
		}
	}
	Barrier::~Barrier()
	{
	}
	void Barrier::Draw() const
	{
		for (size_t i = 0; i < WALL_NUM; i++)
			walls[i]->drawCenter(bind_playerPos + m_offsetpos[i], { 40,120,200 }, siv::Palette::Lightpink);// DrawCenter();
	}
	void Barrier::Update()
	{
	}
}