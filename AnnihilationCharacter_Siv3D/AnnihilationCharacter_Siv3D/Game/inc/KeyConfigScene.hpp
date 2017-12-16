#pragma once

#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;
}


namespace game {

	struct GamePadData;

	class KeyConfigScene :public MySceneBase {
		std::unique_ptr<GamePadData> m_gamePadData;
		std::unique_ptr<elipmocframework::FontObject> m_keyName[3];
		std::unique_ptr<elipmocframework::FontObject> m_keyCode[3];
		std::unique_ptr<elipmocframework::FontObject> m_decision;
		int m_selectIndex = 0;

	public:
		KeyConfigScene();
		~KeyConfigScene();
		void draw()const override;
		void update() override;
		void init()override;

	};
}

