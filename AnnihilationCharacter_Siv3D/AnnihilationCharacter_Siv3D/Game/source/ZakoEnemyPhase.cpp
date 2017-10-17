#include "ZakoEnemyPhase.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "GameMaster.hpp"
#include "BulletList.hpp"
#include "GameCounter.hpp"
#include "EnemyControl.hpp"
#include "TerrainControl.hpp"

namespace game {
	ZakoEnemyPhase::ZakoEnemyPhase(const Level level, const siv::Vec2& playerBindPos, const GameCounterReader& count,BulletList& bulletList,EnemyControl& enemyControl,TerrainControl& terrainControl):
		m_level(level),
		m_enemyList(std::make_unique<EnemyList>()),
		m_enemyBuilder(std::make_unique<EnemyBuilder>(playerBindPos)),
		m_count(count),
		m_bulletList(bulletList),
		m_enemyControl(enemyControl),
		m_terrainControl(terrainControl)
	{
		while (index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime <m_count.GetCount())
		{
			index++;
		}

	}

	void ZakoEnemyPhase::Draw() const
	{
		m_enemyList->Draw();
	}
	void ZakoEnemyPhase::Update()
	{
		while (
			index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime == m_count.GetCount()
			)
		{
			m_enemyList->push_back(
				m_enemyBuilder->EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index], m_level,m_bulletList)
			);
			index++;
		}
		m_enemyList->Update();
		if (m_terrainControl.IsFinished())
			m_enemyControl.SwitchBossPhase();
	}

	ZakoEnemyPhase::~ZakoEnemyPhase() = default;
}