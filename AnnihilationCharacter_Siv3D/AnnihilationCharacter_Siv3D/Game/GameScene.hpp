#pragma once
#include "SceneBase.hpp"
#include "FontObject.hpp"
#include "Player.hpp"

namespace game {
	class GameScene :public MySceneBase {
		 Player player;
	public:
		virtual void init()override {
			player.SetPos({50, 50}).SetText(m_data->player);
		}
		virtual void update()override {
			player.Update();
		}
		virtual void draw() const override {

			player.Draw();
		}
	};
}