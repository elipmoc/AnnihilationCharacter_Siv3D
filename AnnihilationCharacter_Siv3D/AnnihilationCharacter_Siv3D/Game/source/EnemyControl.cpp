#include "EnemyControl.hpp"
#include "EnemyBuilder.hpp"
#include "ZakoEnemyPhase.hpp"
#include "BulletList.hpp"
#include "GameCounter.hpp"

namespace game {
	EnemyControl::EnemyControl(const Level level,const siv::Vec2& playerBindPos,const GameCounterReader& count):
		m_level(level),
		m_bulletList(std::make_unique<BulletList>(1000)),
		m_count(count),
		m_zakoEnemyPhase(std::make_unique<ZakoEnemyPhase>(level,playerBindPos,count,*m_bulletList))

	{
		
	}
	
	EnemyControl::~EnemyControl() = default;

	void EnemyControl::Draw() const
	{
		m_zakoEnemyPhase->Draw();
		m_bulletList->Draw();
	}

	void EnemyControl::Update()
	{
		m_zakoEnemyPhase->Update();
		m_bulletList->Update();
	}
}
