#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"

namespace game {
	EnemyControl::EnemyControl():m_enemyList(std::make_unique<EnemyList>())
	{
		EnemyInfo info;
		info.startPos={ 800,500 };
		info.stopPos = { 100,200 };
		info.endPos = { 400,20 };
		info.model = "TestModel";
		info.action = "TestAction";
		info.barrage = "TestBarrage";
		m_enemyList->push_back(
			EnemyBuilder::EnemyBuild(info)
		);
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
