#include "ZakoEnemyPhase.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "EnemyPhaseControl.hpp"
#include "TerrainControl.hpp"
#include "ZakoEnemyListControl.hpp"

namespace game {
	ZakoEnemyPhase::ZakoEnemyPhase(const Level level, const siv::Vec2& playerBindPos, const GameCounterReader& counter,BulletList& bulletList,EnemyPhaseControl& enemyControl,TerrainControl& terrainControl):
		m_enemyControl(enemyControl),
		m_terrainControl(terrainControl),
		m_zakoEnemyListControl(std::make_unique<ZakoEnemyListControl>(level,counter,bulletList,std::make_unique<EnemyBuilder>(playerBindPos)))
	{

	}

	void ZakoEnemyPhase::Draw() const
	{
		m_zakoEnemyListControl->Draw();
	}
	void ZakoEnemyPhase::Update()
	{
		m_zakoEnemyListControl->Update();

		if (m_terrainControl.IsFinished())
			m_enemyControl.SwitchBossPhase();
	}

	ZakoEnemyPhase::~ZakoEnemyPhase() = default;
}