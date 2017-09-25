#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "GameMaster.hpp"

namespace game {
	EnemyControl::EnemyControl(const Level level):
		m_level(level),
		m_enemyList(std::make_unique<EnemyList>())
	{

		
	}


	EnemyControl::~EnemyControl() = default;

	void EnemyControl::Draw() const
	{
		m_enemyList->Draw();
	}

	void EnemyControl::Update()
	{
		while(
			index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime==count
			)
		{
			m_enemyList->push_back(
				EnemyBuilder::EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index],m_level)
			);
			index++;
		}
		count++;
		m_enemyList->Update();
	}
}
