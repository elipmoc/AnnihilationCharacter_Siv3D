#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;
}

namespace game {

	//主人公選択シーン
	class SelectPlayerScene :public MySceneBase {
		const siv::Font m_guideFont;

		//主人公の文字
		std::unique_ptr<elipmocframework::FontObject> m_playerFonts[3];
		int m_actionInterval = 0;
		int m_selectIndex=1;
	public:
		SelectPlayerScene() :m_guideFont(20) {}
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}