#pragma once
#include "SceneBase.hpp"
#include "FontObject.hpp"

namespace game {
	class Player;
	class GameScene :public MySceneBase {
		std::unique_ptr<Player> m_player;
	public:
		GameScene();
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}