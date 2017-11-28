#pragma once
#include "SceneBase.hpp"


namespace game {
	class ClearScene :public MySceneBase {
		siv::Font font1;
		siv::Font font2;
	public:

		virtual void init()override {
			siv::SoundAsset(L"bgm").stop();
		}

		virtual void update()override {
			if (siv::Input::KeyZ.clicked)
				changeScene(L"Title");
			font1(L"�N���A�I�I").drawCenter(siv::Window::Center());
			font2(L"(*^^*)").drawCenter(siv::Window::Center().x, siv::Window::Center().y + 50);
		}

		virtual void draw() const override {
		}
	};
}