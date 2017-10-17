#include "ZakoEnemyListControl.hpp"
#include "GameMaster.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "EnemyInfo.hpp"
#include "GameCounter.hpp"
#include "Enemy.hpp"

namespace game {

	ZakoEnemyListControl::ZakoEnemyListControl(const Level level, const GameCounterReader& counter, BulletList& bulletList,std::unique_ptr<EnemyBuilder> enemyBuilder)
		:m_enemyBuilder(std::move(enemyBuilder)),
		m_enemyList(std::make_unique<EnemyList>()),
		m_bulletList(bulletList),
		m_counter(counter),
		m_level(level)
	{
		while (index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime <m_counter.GetCount())
		{
			index++;
		}
	}

	ZakoEnemyListControl::~ZakoEnemyListControl() = default;

	void ZakoEnemyListControl::Update()
	{
		while (
			index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime == m_counter.GetCount()
			)
		{
			m_enemyList->push_back(
				m_enemyBuilder->EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index], m_level, m_bulletList)
			);
			index++;
		}
		m_enemyList->Update();
	}

	void ZakoEnemyListControl::Draw() const
	{
		m_enemyList->Draw();
	}
}