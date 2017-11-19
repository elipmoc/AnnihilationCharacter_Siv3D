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
		m_colliObject->Disable();
		m_offsetpos[0] = { DISTANCE + 44,0 + 44 };
		m_offsetpos[1] = { DISTANCE+44,DISTANCE+44 };
		m_offsetpos[2] = { 0+44,DISTANCE+44 };
		m_offsetpos[3] = { -DISTANCE + 44,DISTANCE+44 };
		m_offsetpos[4] = { -DISTANCE + 44,0 + 44 };
		m_offsetpos[5] = { -DISTANCE + 44,-DISTANCE + 44 };
		m_offsetpos[6] = { 0 + 44,-DISTANCE + 44 };
		m_offsetpos[7] = { DISTANCE + 44,-DISTANCE + 44 };
		for (size_t i = 0; i < WALL_NUM; i++) {
			walls[i] = std::make_unique<elipmocframework::GlowText>(siv::Font(),L"��",40);
			walls[i]->SetGlowColor({ 40,120,200 });
			walls[i]->SetColor(siv::Palette::Lightpink);
		}
	}
	Barrier::~Barrier()
	{
	}
	void Barrier::SetBarrier()
	{
		count = 0;
		m_colliObject->Enable();
	}
	void Barrier::Draw() const
	{
		if (count != ENABLE_TIME) {
			for (size_t i = 0; i < WALL_NUM; i++)
				walls[i]->DrawCenter();
		}
	}
	void Barrier::Update()
	{
		for (size_t i = 0; i < WALL_NUM; i++)
			walls[i]->SetPos(bind_playerPos + m_offsetpos[i]);
		if (count != ENABLE_TIME) {
			count++;
			if (count == ENABLE_TIME)
				m_colliObject->Disable();
		}
	}
}