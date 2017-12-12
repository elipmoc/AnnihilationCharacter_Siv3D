#pragma once
#include "SceneBase.hpp"

namespace game {

	class KeyConfigScene :public MySceneBase {

	public:
		void draw()const override;
		void update() override;
		void init()override;

	};
}

