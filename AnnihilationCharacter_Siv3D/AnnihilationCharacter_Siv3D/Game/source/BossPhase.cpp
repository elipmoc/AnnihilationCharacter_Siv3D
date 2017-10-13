#include "BossPhase.hpp"
#include "BossEnemyTalk.hpp"
namespace game {
	BossPhase::BossPhase(Level level, const siv::Vec2 & playerRefPos, BulletList & bulletList):
		m_level(level),
		m_bulletList(bulletList),
		m_test(std::make_unique<BossEnemyTalk>(siv::Vec2(160,70)))
	{}

	BossPhase::~BossPhase() = default;

	void BossPhase::Draw() const
	{
		m_test->Draw();
	}
	void BossPhase::Update()
	{
		m_test->Update();
	}
}