#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;
}

namespace game {

	class ModeSelectScene : public MySceneBase {
		std::unique_ptr<elipmocframework::FontObject> m_gameStartFont;
		std::unique_ptr<elipmocframework::FontObject> m_keyConfigFont;
	public:
		ModeSelectScene();
		~ModeSelectScene();
		virtual void init()override;
		virtual void update()override;
		virtual void draw()const override;
	};

}