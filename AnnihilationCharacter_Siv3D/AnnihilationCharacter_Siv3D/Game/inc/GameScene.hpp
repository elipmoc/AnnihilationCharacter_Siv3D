#pragma once
#include "SceneBase.hpp"
#include "FontObject.hpp"

namespace game {
	class HpUi;
	class BarrierUi;
	class Player;
	class TerrainControl;
	class EnemyPhaseControl;
	class PowerGage;
	class GameCounter;
	class GameScene :public MySceneBase {
		std::unique_ptr<EnemyPhaseControl> m_enemyControl;
		std::unique_ptr<Player> m_player;
		std::unique_ptr<PowerGage> m_powerGage;
		std::unique_ptr<TerrainControl> m_terrainControl;
		std::unique_ptr<HpUi> m_hpUi;
		std::unique_ptr<BarrierUi> m_barrierUi;
		std::unique_ptr<GameCounter> m_gameCounter;
		int m_slowCount = 0;
		bool m_slowFlag = false;
	public:
		GameScene();
		~GameScene();
		void SetSlow();
		void UnSetSlow();
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}