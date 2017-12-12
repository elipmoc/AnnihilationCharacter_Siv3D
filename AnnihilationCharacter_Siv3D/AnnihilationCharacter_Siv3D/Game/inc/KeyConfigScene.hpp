#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;
}


namespace game {

	class KeyConfigScene :public MySceneBase {
		std::unique_ptr<elipmocframework::FontObject> m_keyName[3];
		std::unique_ptr<elipmocframework::FontObject> m_keyCode[3];
		int m_selectIndex = 0;
	public:
		void draw()const override;
		void update() override;
		void init()override;

	};
}

