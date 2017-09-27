#include "Enemy.hpp"
#include "EnemyBuilder.hpp"
#include "EnemyModelInfo.hpp"
#include "EnemyActionBase.hpp"
#include "BarrageBase.hpp"
#include "FontObject.hpp"
//#include "TestBarrage.hpp"
#include "EnemyAction\EnemyAction2.hpp"
#include "EnemyAction\TestEnemyAction.hpp"
#include "TestEnemyModel.hpp"
#include "EnemyModel\Model01.hpp"
#include "EnemyModel\Model02.hpp"
#include "EnemyModel\Model03.hpp"
#include "EnemyModel\Model04.hpp"
#include "EnemyBarrage\UpShot.hpp"
#include "EnemyBarrage\HorizontalShotOne.hpp"
#include "EnemyBarrage\HorizontalShotOnes.hpp"
#include "EnemyBarrage\HorizontalShot3Way.hpp"

namespace game {

	EnemyBuilder::EnemyBuilder(const siv::Vec2& playerBindPos)
		:m_playerBindPos(playerBindPos)
	{
		//m_barrageMap["TestBarrage"] = std::make_unique<MakeBarrageGenerator<TestBarrage>>();
		m_barrageMap["HorizontalShotOne"] = std::make_unique<MakeBarrageGenerator<HorizontalShotOne>>();
		m_barrageMap["HorizontalShotOnes"] = std::make_unique<MakeBarrageGenerator<HorizontalShotOnes>>();
		m_barrageMap["HorizontalShot3Way"] = std::make_unique<MakeBarrageGenerator<HorizontalShot3Way>>();
		m_barrageMap["UpShot"] = std::make_unique<MakeBarrageGenerator<UpShot>>();
		m_actionMap["Action1"] = std::make_unique<TestEnemyAction>();
		m_actionMap["Action2"] = std::make_unique<EnemyAction2>();
		m_modelMap["TestModel"] = std::make_unique<TestEnemyModel>();
		m_modelMap["Model01"] = std::make_unique<Model01>();
		m_modelMap["Model02"] = std::make_unique<Model02>();
		m_modelMap["Model03"] = std::make_unique<Model03>();
		m_modelMap["Model04"] = std::make_unique<Model04>();
	}

	EnemyBuilder::~EnemyBuilder()
	{
	}


	std::unique_ptr<Enemy> EnemyBuilder::EnemyBuild(const EnemyInfo& info, const Level level)
	{
		using elipmocframework::FontObject;
		auto&& enemyFont = std::make_unique<FontObject>(12,L"‚l‚r ‚oƒSƒVƒbƒN");
		enemyFont->SetPos(info.startPos);
		enemyFont->AddAction(m_actionMap[info.action]->GenerateEnemyAction(info.startPos,info.stopPos,info.endPos,info.waitTime));
		return
			std::make_unique<Enemy>(
				info.lifeTime,
				info.barrageStartTime,
				m_modelMap[info.model]->GenerateEnemyModelInfo(),
				m_barrageMap[info.barrage]->GenerateBarrage(level,enemyFont->GetRefPos(),m_playerBindPos),
				std::move(enemyFont)
				);
	}
}