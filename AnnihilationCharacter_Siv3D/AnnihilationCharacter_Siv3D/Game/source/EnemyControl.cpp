#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "GameMaster.hpp"
#include "BulletList.hpp"

namespace game {
	EnemyControl::EnemyControl(const Level level,const siv::Vec2& playerBindPos,const int startCount):
		m_level(level),
		m_enemyList(std::make_unique<EnemyList>()),
		m_enemyBuilder(std::make_unique<EnemyBuilder>(playerBindPos)),
		m_bulletList(std::make_unique<BulletList>(1000)),
		m_count(startCount)
	{
		while (index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime <m_count)
		{
			index++;
		}
		
	}
	
	EnemyControl::~EnemyControl() = default;

	void EnemyControl::Draw() const
	{
		m_enemyList->Draw();
		m_bulletList->Draw();
	}

	void EnemyControl::Update()
	{
		while(
			index < GameMaster::GetInstance().GetEnemyInfoList().size() &&
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime==m_count
			)
		{
			m_enemyList->push_back(
				m_enemyBuilder->EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index],m_level,*m_bulletList.get())
			);
			index++;
		}
		m_count++;
		m_enemyList->Update();
		m_bulletList->Update();
	}
}
