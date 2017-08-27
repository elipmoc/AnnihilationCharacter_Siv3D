#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"
#include "GameMaster.hpp"

namespace game {
	EnemyControl::EnemyControl():
		m_enemyList(std::make_unique<EnemyList>())
	{

		/*auto info=std::make_unique<EnemyInfo>();
		info->bornTime = 120;
		info->lifeTime = 300;
		info->barrageStartTime = 220;
		info->startPos={ 800,500 };
		info->stopPos = { 100,200 };
		info->endPos = { 400,280 };
		info->model = "TestModel";
		info->action = "TestAction";
		info->barrage = "TestBarrage";
		auto info2 = std::make_unique<EnemyInfo>();
		info2->bornTime = 120;
		info2->lifeTime = 400;
		info2->barrageStartTime = 220;
		info2->startPos = { 800,500 };
		info2->stopPos = { 100,200 };
		info2->endPos = { 200,280 };
		info2->model = "TestModel";
		info2->action = "TestAction";
		info2->barrage = "TestBarrage";
		auto info3 = std::make_unique<EnemyInfo>();
		info3->bornTime = 120;
		info3->lifeTime = 500;
		info3->barrageStartTime = 220;
		info3->startPos = { 800,500 };
		info3->stopPos = { 100,200 };
		info3->endPos = { 0,280 };
		info3->model = "TestModel";
		info3->action = "TestAction";
		info3->barrage = "TestBarrage";
		m_enemyInfoList.push_back(std::move(info));
		m_enemyInfoList.push_back(std::move(info2));
		m_enemyInfoList.push_back(std::move(info3));*/
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
				EnemyBuilder::EnemyBuild(*GameMaster::GetInstance().GetEnemyInfoList()[index])
			);
			index++;
		}
		count++;
		m_enemyList->Update();
	}
}
