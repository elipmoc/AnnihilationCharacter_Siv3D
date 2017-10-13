#include "EnemyControl.hpp"
#include "EnemyBuilder.hpp"
#include "ZakoEnemyPhase.hpp"
#include "BossPhase.hpp"
#include "BulletList.hpp"
#include "GameCounter.hpp"

namespace game {
	EnemyControl::EnemyControl(const Level level,const siv::Vec2& playerRefPos,const GameCounterReader& count):
		m_level(level),
		m_bulletList(std::make_unique<BulletList>(1000)),
		m_count(count),
		m_phase(std::make_unique<ZakoEnemyPhase>(level,playerRefPos,count,*m_bulletList)),
		m_playerRefPos(playerRefPos)
	{
		
	}
	
	EnemyControl::~EnemyControl() = default;

	void EnemyControl::SwitchBossPhase()
	{
		static bool hoge = false;
		if (hoge)return;
		hoge = true;
		m_phase = std::make_unique<BossPhase>(m_level, m_playerRefPos, *m_bulletList);
	}

	void EnemyControl::Draw() const
	{
		m_phase->Draw();
		m_bulletList->Draw();
	}

	void EnemyControl::Update()
	{
		m_phase->Update();
		m_bulletList->Update();
	}
}
