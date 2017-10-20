#pragma once
#include "BasePhase.hpp"
#include "SceneBase.hpp"

namespace game {
	class TerrainControl;
	class BossEnemyTalk;
	class BulletList;
	class Boss;
	class BossPhase :public BasePhase{
		std::unique_ptr<Boss> m_boss;
		std::unique_ptr<BossEnemyTalk> m_test;
		TerrainControl& m_terrainControl;
	public:
		BossPhase(Level level, const siv::Vec2& playerRefPos, BulletList&,TerrainControl&);
		~BossPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}