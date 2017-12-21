#pragma once
#include "SceneBase.hpp"


namespace game {
	class GameOverScene :public MySceneBase {
		siv::Font font1;
		siv::Font font2;
	public:

		virtual void init()override {
			siv::SoundAsset(L"bgm").stop();
			siv::SoundAsset(L"bossBgm").stop();
		}

		virtual void update()override {
			if ((siv::Input::KeyZ | GamePadInput::GetInstance().GetJump()).clicked)
				changeScene(L"Title");
			font1(L"‚ ‚È‚½‚Í‚µ‚É‚Ü‚µ‚½").drawCenter(siv::Window::Center());
			font2(L"m9(^„D^)").drawCenter(siv::Window::Center().x,siv::Window::Center().y+50);
		}

		virtual void draw() const override {
		}
	};
}