#pragma once
#include "BasePhase.hpp"
#include "SceneBase.hpp"

namespace game {
	class TerrainControl;
	class BossTalk;
	class BulletListCreator;
	class BossBehaviorMakeList;
	class Boss;
	class PowerSpawn;
	class BossHpGage;
	class BossPhase :public BasePhase{
		const std::array<int,3> m_hpList = { 50,100,0 };
		const std::array<std::string, 3> m_terrainNameList = { "Boss1","Boss2","Boss2" };

		//現在のhpListとterrainNameListの要素を保存するために使用
		size_t listIndex=0;
		//ボスが死ぬまでの遅延時間
		int m_bossEndCount=860;
		std::unique_ptr<BossBehaviorMakeList> m_bossBehaviorMakeList;
		std::unique_ptr<PowerSpawn> m_powerSpawn;
		std::unique_ptr<Boss> m_boss;
		std::unique_ptr<BossTalk> m_test;
		std::unique_ptr<BossHpGage> m_bossHpGage;
		TerrainControl& m_terrainControl;
	public:
		BossPhase(Level level, const siv::Vec2& playerRefPos, BulletListCreator&,TerrainControl&);
		~BossPhase();
		bool IsClear()const noexcept;
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}