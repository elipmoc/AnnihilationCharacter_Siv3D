#pragma once
#include "BossBehavior.hpp"

namespace elipmocframework {
	class ParticleList;
}

namespace game {
	class BossBehaviorWait :public BossBehavior {
		int m_count = 0;
	public:
		std::unique_ptr<elipmocframework::ParticleList> m_particleList;
		BossBehaviorWait(const Level, const siv::Vec2&, const BulletListCreator&);
		virtual void YawarakaUpdate() override final;
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate() override final;
	};
}