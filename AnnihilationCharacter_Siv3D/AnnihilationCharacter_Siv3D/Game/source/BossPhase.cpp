#include "BossPhase.hpp"

namespace game {
	BossPhase::BossPhase(Level level, const siv::Vec2 & playerRefPos, BulletList & bulletList):
		m_level(level),
		m_bulletList(bulletList)
	{}

	BossPhase::~BossPhase() = default;

	void BossPhase::Draw() const
	{
		siv::Println(L"BossPhase");
	}
	void BossPhase::Update()
	{
	}
}