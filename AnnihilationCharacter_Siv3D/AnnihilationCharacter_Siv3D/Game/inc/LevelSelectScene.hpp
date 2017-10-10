#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class GlowText;
}

namespace game {

	//難易度選択シーン
	class LevelSelectScene :public MySceneBase {
		const siv::Font m_guideFont;

		//難易度の文字
		std::unique_ptr<elipmocframework::GlowText> m_levelFonts[3];
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