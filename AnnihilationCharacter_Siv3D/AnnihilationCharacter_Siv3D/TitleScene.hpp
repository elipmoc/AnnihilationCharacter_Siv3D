#pragma once
#include "SceneBase.hpp"
namespace game {
	
	class TitleScene :public MySceneBase {
		const siv::Font titleFont;
		const siv::Font subTitleFont;
		const siv::Font guideFont;
		double angle=0;
	public:
		TitleScene():titleFont(40),subTitleFont(20),guideFont(15){}
		virtual void init()override {
			siv::Graphics::SetBackground(siv::Palette::Black);
		}
		virtual void update()override {
			angle+=3;
		}
		virtual void draw() const override{
			using namespace siv::Math;
			using namespace siv::Window;
			titleFont(L"è¡ñ≈ï∂éö").drawCenter(Center().x, Center().y - 70);
			subTitleFont(L"Å`AnnihilationCharacterÅ`").drawCenter(Center().x,Center().y, siv::Palette::Gold);
			guideFont(L"Start EnterKey").drawCenter(Center().x, Center().y + 40, { 0,100,255,static_cast<uint32>(128 - 127 * Sin(Radians(angle))) });
		}
	};
}