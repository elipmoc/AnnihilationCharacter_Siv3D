#include "Enemy.hpp"
#include "EnemyBuilder.hpp"
#include "EnemyModelInfo.hpp"
#include "EnemyActionBase.hpp"
#include "BarrageBase.hpp"
#include "FontObject.hpp"
#include "TestBarrage.hpp"
#include "EnemyAction\TestEnemyAction.hpp"
#include "TestEnemyModel.hpp"
#include "EnemyModel\Model01.hpp"
#include "EnemyBarrage\HorizontalShotOne.hpp"
#include "EnemyBarrage\HorizontalShot3Way.hpp"

namespace game {
	class EnemyBuilder::EnemyBuilderImpl {
		std::map<std::string, std::unique_ptr<BarrageGenerator>> m_barrageMap;
		std::map<std::string, std::unique_ptr<EnemyActionBase>> m_actionMap;
		std::map<std::string, std::unique_ptr<EnemyModelInfoGenerator>> m_modelMap;
	public:
		std::unique_ptr<Enemy> EnemyBuild(const EnemyInfo&);
		EnemyBuilderImpl();
	};

	EnemyBuilder::EnemyBuilderImpl::EnemyBuilderImpl() {
		m_barrageMap["TestBarrage"] = std::make_unique<MakeBarrageGenerator<TestBarrage>>();
		m_barrageMap["HorizontalShotOne"] = std::make_unique<MakeBarrageGenerator<HorizontalShotOne>>();
		m_barrageMap["HorizontalShot3Way"] = std::make_unique<MakeBarrageGenerator<HorizontalShot3Way>>();
		m_actionMap["TestAction"] = std::make_unique<TestEnemyAction>();
		m_modelMap["TestModel"] = std::make_unique<TestEnemyModel>();
		m_modelMap["Model01"] = std::make_unique<Model01>();
	}


	std::unique_ptr<Enemy> EnemyBuilder::EnemyBuilderImpl::EnemyBuild(const EnemyInfo& info)
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
				m_barrageMap[info.barrage]->GenerateBarrage(enemyFont->GetRefPos()),
				std::move(enemyFont)
				);
	}

	std::unique_ptr<Enemy> EnemyBuilder::EnemyBuild(const EnemyInfo& info)
	{
		return impl.EnemyBuild(info);
	}	
	
	//ƒCƒ“ƒXƒ^ƒ“ƒX‰»
	EnemyBuilder::EnemyBuilderImpl EnemyBuilder::impl;
}