#pragma once

namespace game {
	class BulletList;
	class BossPhase {
		const int m_level;
		BulletList& m_bulletList;
	public:
		BossPhase(int level, const siv::Vec2& playerRefPos, BulletList&);
		~BossPhase();

	};
}