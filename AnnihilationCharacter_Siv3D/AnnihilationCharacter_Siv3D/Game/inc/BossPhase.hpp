#pragma once
#include "BasePhase.hpp"
#include "SceneBase.hpp"

namespace game {
	class TerrainControl;
	class BossTalk;
	class BulletListCreator;
	class Boss;
	class PowerSpawn;
	class BossHpGage;
	class BossPhase :public BasePhase{
		std::array<int,2> m_hpList = { 50,50 };
		std::array<std::string, 2> m_terrainNameList = { "Boss1","Boss2" };

		//åªç›ÇÃhpListÇ∆terrainNameListÇÃóvëfÇï€ë∂Ç∑ÇÈÇΩÇﬂÇ…égóp
		size_t listIndex=0;

		std::unique_ptr<PowerSpawn> m_powerSpawn;
		std::unique_ptr<Boss> m_boss;
		std::unique_ptr<BossTalk> m_test;
		std::unique_ptr<BossHpGage> m_bossHpGage;
		TerrainControl& m_terrainControl;
	public:
		BossPhase(Level level, const siv::Vec2& playerRefPos, BulletListCreator&,TerrainControl&);
		~BossPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}