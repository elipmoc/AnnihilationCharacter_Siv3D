#pragma once
#include "SceneBase.hpp"
#include "FontObject.hpp"

namespace game {
	class HpUi;
	class Player;
	class TerrainControl;
	class GameScene :public MySceneBase {
		std::unique_ptr<Player> m_player;
		std::unique_ptr<TerrainControl> m_terrainControl;
		std::unique_ptr<HpUi> m_hpUi;
	public:
		GameScene();
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}