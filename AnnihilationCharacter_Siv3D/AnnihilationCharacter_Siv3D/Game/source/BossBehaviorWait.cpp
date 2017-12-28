#include "BossBehaviorWait.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"
#include "Boss.hpp"
#include "ParticleList.hpp"

namespace game {
	using elipmocframework::ParticleList;
	using elipmocframework::ParticleState;

	BossBehaviorWait::BossBehaviorWait(const Level level, const siv::Vec2 & playerRefPos, const BulletListCreator & bulletListCreator)
		:BossBehavior(level,playerRefPos,bulletListCreator)
	{
		ParticleState state;
		state.color = siv::Palette::Darkred;
		state.lifeTime = 200000;
		state.particleLifeTime = 200;
		state.particleNum = 15;
		state.particleMaxNum = 90;
		state.speed = 3;
		state.vspeed = 0.0005;
		state.fireInterval = 40;
		state.text = L"”j";
		state.vopacity = -2.5;
		m_particleList = std::make_unique<ParticleList>(20, state);
		m_particleList->Set(Boss::BOSS_POS);
	}
	void BossBehaviorWait::YawarakaUpdate()
	{
		m_particleList->Update();
		m_particleList->Draw();
		if (m_count % 30 == 0)
			siv::SoundAsset(L"bossDead").playMulti();

		m_count++;
		
	}
	void BossBehaviorWait::NormalUpdate()
	{
		YawarakaUpdate();
	}
	void BossBehaviorWait::RengokuUpdate()
	{
		YawarakaUpdate();
	}
}