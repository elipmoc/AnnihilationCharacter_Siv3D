#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;

}

namespace game {
	class BulletListCreator;
	class BossBehavior;

	//ボスクラス
	class Boss {
		std::unique_ptr<BossBehavior> m_bossBehavior;
		const Level m_level;
		BulletListCreator& m_bulletListCreator;
		const siv::Vec2& m_playerRefPos;
		std::unique_ptr<elipmocframework::FontObject> m_fontObject;
	public:
		Boss(Level level,const siv::Vec2& playerRefPos, BulletListCreator&);
		~Boss();
		void SetBossBehavior(std::unique_ptr<BossBehavior>);
		void Update();
		void Draw()const;
	};

}