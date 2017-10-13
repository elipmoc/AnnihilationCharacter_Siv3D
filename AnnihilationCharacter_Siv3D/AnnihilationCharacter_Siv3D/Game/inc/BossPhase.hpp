#pragma once
#include "BasePhase.hpp"
#include "SceneBase.hpp"

namespace game {
	class BossEnemyTalk;
	class BulletList;
	class BossPhase :public BasePhase{
		const Level m_level;
		BulletList& m_bulletList;
		std::unique_ptr<BossEnemyTalk> m_test;
	public:
		BossPhase(Level level, const siv::Vec2& playerRefPos, BulletList&);
		~BossPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}