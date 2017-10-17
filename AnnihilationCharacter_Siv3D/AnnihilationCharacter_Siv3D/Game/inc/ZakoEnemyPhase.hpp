#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"
#include "BasePhase.hpp"

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyBuilder;
	class BulletList;
	class GameCounterReader;
	class EnemyPhaseControl;
	class TerrainControl;
	class ZakoEnemyListControl;

	class ZakoEnemyPhase :public BasePhase{
		std::unique_ptr<ZakoEnemyListControl> m_zakoEnemyListControl;
		EnemyPhaseControl& m_enemyControl;
		TerrainControl& m_terrainControl;
	public:
		/*
		param:
		難易度,主人公のRef座標,スタートするタイミング
		*/
		ZakoEnemyPhase(const Level, const siv::Vec2&, const GameCounterReader&,BulletList&,EnemyPhaseControl&,TerrainControl&);
		~ZakoEnemyPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;
	};
}