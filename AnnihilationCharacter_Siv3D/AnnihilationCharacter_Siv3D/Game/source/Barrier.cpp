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