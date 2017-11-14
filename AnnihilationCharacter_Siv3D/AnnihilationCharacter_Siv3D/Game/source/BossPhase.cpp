#include "BossPhase.hpp"
#include "BossEnemyTalk.hpp"
#include "Boss.hpp"
#include "TerrainControl.hpp"
#include "BossPhase.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossPhase::BossPhase(Level level, const siv::Vec2 & playerRefPos, BulletListCreator & bulletListCreator,TerrainControl& terrainControl):
		m_test(std::make_unique<BossEnemyTalk>(siv::Vec2(160,70))),
		m_terrainControl(terrainControl),
		m_boss(std::make_unique<Boss>(level,playerRefPos,bulletListCreator))
	{
	}

	BossPhase::~BossPhase() = default;

	void BossPhase::Draw() const
	{
		if (m_test != nullptr)
			m_test->Draw();
		m_boss->Draw();
	}
	void BossPhase::Update()
	{
		if (m_test != nullptr) {
			m_test->Update();
			if (m_test->IsFinished()) {
				m_test = nullptr;
				m_boss->SetBossBehavior();
			}
		}
		m_boss->Update();
	}
}