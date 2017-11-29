#pragma once
#include "SceneBase.hpp"

namespace game {
	class BulletListCreator;

	class BossBehavior {
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		const Level m_level;

	protected:
		BulletListCreator& GetBulletListCreator() { return *m_bulletListCreator; };
		
	public:
		BossBehavior::BossBehavior(const Level ,const BulletListCreator & bulletListCreator);
		void Update();
		virtual void YawarakaUpdate() = 0;
		virtual void NormalUpdate() = 0;
		virtual void RengokuUpdate() = 0;
	};
}