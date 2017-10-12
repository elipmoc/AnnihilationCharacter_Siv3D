#include "BossPhase.hpp"

namespace game {
	BossPhase::BossPhase(int level, const siv::Vec2 & playerRefPos, BulletList & bulletList):
		m_level(level),
		m_bulletList(bulletList)
	{}

	BossPhase::~BossPhase() = default;

	void BossPhase::Draw() const
	{
	}
	void BossPhase::Update()
	{
	}
}