#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;

}

namespace game {
	class BulletList;
	//ボスクラス
	class Boss {
		const Level m_level;
		BulletList& m_bulletList;
		const siv::Vec2& m_playerRefPos;
		std::unique_ptr<elipmocframework::FontObject> m_fontObject;
	public:
		Boss(Level level,const siv::Vec2& playerRefPos, BulletList&);
		~Boss();
		void Update();
		void Draw()const;
	};

}