#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "TestEnemy.hpp"

namespace game {

	EnemyControl::EnemyControl():m_enemyList(std::make_unique<EnemyList>())
	{
		m_enemyList->push_back(std::make_unique<TestEnemy>(siv::Vec2{ 800,500 }, siv::Vec2{ 400,200 }, siv::Vec2{300,150},20));
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
