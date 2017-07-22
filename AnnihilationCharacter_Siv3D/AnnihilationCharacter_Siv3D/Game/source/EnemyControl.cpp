#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBase.hpp"

namespace game {

	EnemyControl::EnemyControl():m_enemyList(std::make_unique<EnemyList>())
	{
		m_enemyList->push_back(std::make_unique<EnemyBase>(siv::Vec2{ 0,0 }, siv::Vec2{ 10,10 }, siv::Vec2{50,50}));
	}
	EnemyControl::~EnemyControl() = default;
	void EnemyControl::Draw() const
	{
		m_enemyList->Draw();
	}
	void EnemyControl::Update()
	{
		m_enemyList->Update();
	}
}
