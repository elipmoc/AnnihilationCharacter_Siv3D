#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "GameMaster.hpp"
#include "BulletList.hpp"

namespace game {
	EnemyControl::EnemyControl(const Level level,const siv::Vec2& playerBindPos):
		m_level(level),
		m_enemyList(std::make_unique<EnemyList>()),
		m_enemyBuilder(std::make_unique<EnemyBuilder>(playerBindPos)),
		m_bulletList(std::make_unique<BulletList>(1000))
	{

		
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
			GameMaster::GetInstance().GetEnemyInfoList()[index]->bornTime==count
			)
		{
			m_enemyList->push_back(
				m_enemyBuilder->EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index],m_level,*m_bulletList.get())
			);
			index++;
		}
		count++;
		m_enemyList->Update();
		m_bulletList->Update();
	}
}
