#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;
}

namespace game {

	//主人公選択シーン
	class SelectPlayerScene :public MySceneBase {
		const siv::Font guideFont;

		//主人公の文字
		std::unique_ptr<elipmocframework::FontObject> playerFonts[3];
		int actionInterval = 0;
		int selectIndex=1;
	public:
		SelectPlayerScene() :guideFont(20) {}
		virtual void init()override;
		virtual void update()override;
		virtual void draw() const override;
	};
}