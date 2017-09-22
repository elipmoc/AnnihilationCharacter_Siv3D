#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class GlowText;
}

namespace game {

	//��Փx�I���V�[��
	class LevelSelectScene :public MySceneBase {
		const siv::Font m_guideFont;

		//��Փx�̕���
		std::unique_ptr<elipmocframework::GlowText> m_levelFonts[2];
		int m_actionInterval = 0;
		int m_selectIndex = 0;
	public:
		LevelSelectScene();
		~LevelSelectScene();
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}