#pragma once
#include "BossBehavior.hpp"

namespace elipmocframework {
	class ParticleList;
}

namespace game {
	class BossBehaviorWait :public BossBehavior {
		int m_count = 50;
		int m_interval = 50;
	public:
		std::unique_ptr<elipmocframework::ParticleList> m_particleList;
		std::unique_ptr<elipmocframework::ParticleList> m_particleList2;
		BossBehaviorWait(const Level, const siv::Vec2&, const BulletListCreator&);
		virtual void YawarakaUpdate() override final;
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate() override final;
	};
}