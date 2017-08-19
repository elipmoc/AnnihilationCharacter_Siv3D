#pragma once
#include "SceneBase.hpp"

namespace game {

	class GameOverScene :public MySceneBase {
	public:

		virtual void init()override {
		}

		virtual void update()override {
			if (siv::Input::KeyEnter.clicked)
				changeScene(L"Title");
		}

		virtual void draw() const override {
		}
	};
}