#pragma once
#include "SceneBase.hpp"

namespace game {
	class BulletListCreator;

	class BossBehavior {
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		const Level m_level;
		const siv::Vec2& m_playerRefPos;
	protected:
		BulletListCreator& GetBulletListCreator() { return *m_bulletListCreator; };
		
	public:
		siv::Vec2 GetPlayerPos() { return m_playerRefPos; }
		BossBehavior::BossBehavior(const Level ,const siv::Vec2& playerRefPos,const BulletListCreator & bulletListCreator);
		void Update();
		virtual void YawarakaUpdate() = 0;
		virtual void NormalUpdate() = 0;
		virtual void RengokuUpdate() = 0;
	};
}