#pragma once
#include "SceneBase.hpp"
#include "FontEx.hpp"
namespace game {

	class SelectPlayerScene :public MySceneBase {
		const siv::Font testFont;
		elipmocframework::FontObject playerFonts[3];
		int actionInterval = 0;
		int selectIndex=1;
	public:
		SelectPlayerScene() :testFont(20) {
			using namespace siv::Window;
			playerFonts[0].SetText(L"éÂ").SetPos({ Center().x - 50, Center().y });
			playerFonts[1].SetText(L"êl").SetPos(Center()).SetScale(2);
			playerFonts[2].SetText(L"åˆ").SetPos({Center().x + 50, Center().y});
		}
		virtual void init()override {
		}
		virtual void update()override {
			if ((siv::Input::KeyRight.clicked || siv::Input::KeyLeft.clicked) && actionInterval == 0) {
				actionInterval = 5;
				playerFonts[selectIndex].AddAction(elipmocframework::CreateScaleAction(playerFonts[selectIndex], 1, 5));
				if(siv::Input::KeyRight.clicked)
					selectIndex = (selectIndex +1) % 3;
				else 
					selectIndex = (selectIndex + 2) % 3;

				playerFonts[selectIndex].AddAction(elipmocframework::CreateScaleAction(playerFonts[selectIndex], 2, 5));
			}
			if (actionInterval != 0)actionInterval--;
			for(auto&& item:playerFonts)
				item.Update();

		}
		virtual void draw() const override {
			
			for (auto&& item : playerFonts)
				item.DrawCenter();
			testFont(L"éÂêlåˆÇëIÇÒÇ≈Ç≠ÇæÇ≥Ç¢").draw({50,50});
		}
	};
}