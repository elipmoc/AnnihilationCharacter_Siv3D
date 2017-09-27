#pragma once
#include "SceneBase.hpp"
#include "TitleParticle.hpp"

namespace game {
	
	class TitleScene :public MySceneBase {
		const siv::Font m_titleFont;
		const siv::Font m_subTitleFont;
		const siv::Font m_guideFont;
		double m_angle=0;
		TitleParticle m_titleParticle;
	public:
		TitleScene():m_titleFont(40),m_subTitleFont(20),m_guideFont(15){
		}

		virtual void init()override {
			siv::Graphics::SetBackground(siv::Palette::Black);
		}

		virtual void update()override {
			m_titleParticle.Update();
			if (siv::Input::KeyZ.clicked)
				changeScene(L"LevelSelect");
			m_angle+=3;
		}

		virtual void draw() const override{
			using namespace siv::Math;
			using namespace siv::Window;
			m_titleFont(L"è¡ñ≈ï∂éö").drawCenter(Center().x, Center().y - 70);
			m_subTitleFont(L"Å`AnnihilationCharacterÅ`").drawCenter(Center().x,Center().y, siv::Palette::Gold);
			m_guideFont(L"Start ZKey").drawCenter(Center().x, Center().y + 40, { 0,100,255,static_cast<uint32>(128 - 127 * Sin(Radians(m_angle))) });
			m_titleParticle.Draw();
		}
	};
}