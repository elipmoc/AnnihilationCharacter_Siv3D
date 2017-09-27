#pragma once
#include "SceneBase.hpp"


namespace game {


	class GameOverScene :public MySceneBase {
		siv::Font font1;
		siv::Font font2;
	public:

		virtual void init()override {
		}

		virtual void update()override {
			if (siv::Input::KeyZ.clicked)
				changeScene(L"Title");
			font1(L"あなたはしにました").drawCenter(siv::Window::Center());
			font2(L"m9(^Д^)").drawCenter(siv::Window::Center().x,siv::Window::Center().y+50);
			
		}

		virtual void draw() const override {
		}
	};
}