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
	public:
		GameScene();
		~GameScene();
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}