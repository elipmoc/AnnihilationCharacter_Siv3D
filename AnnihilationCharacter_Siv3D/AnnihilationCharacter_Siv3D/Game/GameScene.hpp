#pragma once
#include "SceneBase.hpp"
#include "FontObject.hpp"

namespace game {
	class GameScene :public MySceneBase {
		elipmocframework::FontObject player;
	public:
		GameScene()  {}
		virtual void init()override {
			player.SetPos({50, 50}).SetText(m_data->player);
		}
		virtual void update()override {
		}
		virtual void draw() const override {
			player.Draw();
		}
	};
}