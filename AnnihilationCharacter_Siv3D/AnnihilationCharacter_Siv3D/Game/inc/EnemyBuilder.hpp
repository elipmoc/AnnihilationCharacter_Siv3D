#pragma once
#include "EnemyInfo.hpp"
#include "SceneBase.hpp"

namespace game {
	class Enemy;
	class BarrageGenerator;
	class EnemyActionBase;
	class EnemyModelInfoGenerator;

	//敵を生成するビルダークラス
	class EnemyBuilder {
		
		std::map<std::string, std::unique_ptr<BarrageGenerator>> m_barrageMap;
		std::map<std::string, std::unique_ptr<EnemyActionBase>> m_actionMap;
		std::map<std::string, std::unique_ptr<EnemyModelInfoGenerator>> m_modelMap;
		//プレイヤー座標の参照
		const siv::Vec2& m_playerBindPos;
	public:
		EnemyBuilder(const siv::Vec2& playerBindPos);
		~EnemyBuilder();
		std::unique_ptr<Enemy> EnemyBuild(const EnemyInfo&,const Level level);
	};
}