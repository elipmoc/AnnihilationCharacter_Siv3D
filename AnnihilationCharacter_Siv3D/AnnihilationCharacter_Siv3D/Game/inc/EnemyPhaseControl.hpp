#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BasePhase;
	class BossPhase;
	class BulletList;
	class GameCounterReader;
	class TerrainControl;

	class EnemyPhaseControl {
		TerrainControl& m_terrainControl;
		const Level m_level;
		std::unique_ptr<BulletList> m_bulletList;
		std::unique_ptr<BasePhase> m_phase;
		std::unique_ptr<BossPhase> m_bossPhase;
		const siv::Vec2& m_playerRefPos;
		int index = 0;

	public:
		/*
		param:
			難易度,主人公のRef座標,スタートするタイミング
		*/
		EnemyPhaseControl(const Level level,const siv::Vec2&,const GameCounterReader&,TerrainControl&);
		~EnemyPhaseControl();
		//ボスフェーズに切り替え
		void SwitchBossPhase();
		void Draw()const;
		void Update();
		//ゲームをクリアするかのフラグ
		bool IsClear();
	};
}