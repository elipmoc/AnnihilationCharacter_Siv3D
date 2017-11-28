#include "EnemyPhaseControl.hpp"
#include "ZakoEnemyPhase.hpp"
#include "BossPhase.hpp"
#include "BulletList.hpp"
#include "TerrainControl.hpp"
#include "BulletListCreator.hpp"

namespace game {
	EnemyPhaseControl::EnemyPhaseControl(const Level level,const siv::Vec2& playerRefPos,const GameCounterReader& count,TerrainControl& terrainControl):
		m_terrainControl(terrainControl),
		m_level(level),
		m_bulletList(std::make_unique<BulletList>(1000)),
		m_phase(std::make_unique<ZakoEnemyPhase>(level,playerRefPos,count,BulletListCreator(*m_bulletList),*this,m_terrainControl)),
		m_playerRefPos(playerRefPos)
	{
		
	}
	
	EnemyPhaseControl::~EnemyPhaseControl() = default;

	void EnemyPhaseControl::SwitchBossPhase()
	{
		m_bossPhase = std::make_unique<BossPhase>(m_level, m_playerRefPos,BulletListCreator( *m_bulletList),m_terrainControl);
	}

	void EnemyPhaseControl::Draw() const
	{
		if (m_bossPhase == nullptr)
			m_phase->Draw();
		else
			m_bossPhase->Draw();

		m_bulletList->Draw();
	}

	void EnemyPhaseControl::Update()
	{
		if (m_bossPhase == nullptr)
			m_phase->Update();
		else
			m_bossPhase->Update();
		m_bulletList->Update();
	}
	bool EnemyPhaseControl::IsClear()
	{
		if (m_bossPhase == nullptr)
			return false;
		else
			return m_bossPhase->IsClear();
	}
}
