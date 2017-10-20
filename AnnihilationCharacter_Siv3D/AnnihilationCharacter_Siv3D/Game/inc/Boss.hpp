#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;

}

namespace game {
	class BulletListCreator;
	//ボスクラス
	class Boss {
		const Level m_level;
		BulletListCreator& m_bulletListCreator;
		const siv::Vec2& m_playerRefPos;
		std::unique_ptr<elipmocframework::FontObject> m_fontObject;
	public:
		Boss(Level level,const siv::Vec2& playerRefPos, BulletListCreator&);
		~Boss();
		void Update();
		void Draw()const;
	};

}