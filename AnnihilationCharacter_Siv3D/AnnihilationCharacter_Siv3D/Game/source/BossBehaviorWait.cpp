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
		state.color = siv::Palette::Orangered;
		state.lifeTime = 200;
		state.particleLifeTime = 200;
		state.particleNum = 15;
		state.particleMaxNum = 90;
		state.speed = 3;
		state.vspeed = 0.0005;
		state.fireInterval = 200;
		state.text = L"è¡";
		state.vopacity = -2.5;
		state.speedBlur = 5;
		m_particleList = std::make_unique<ParticleList>(30, state);
		state.text = L"ñ≈";
		state.color = siv::Palette::White;
		state.particleNum = 50;
		state.particleMaxNum = 50;
		m_particleList2 = std::make_unique<ParticleList>(1, state);
	}
	void BossBehaviorWait::YawarakaUpdate()
	{
		m_particleList->Update();
		m_particleList2->Update();
		m_particleList->Draw();
		m_particleList2->Draw();
		if (m_interval>5&&m_count!=0&&m_count % m_interval == 0) {
			m_particleList->Set(Boss::BOSS_POS);
			siv::SoundAsset(L"bossDead").playMulti();
			m_interval -= 2;
			m_count = 0;
		}
		if(m_interval<5 &&m_interval!=-1)
		{
			siv::SoundAsset(L"bossDead2").playMulti();
			m_interval = -1;
			m_particleList2->Set(Boss::BOSS_POS);
		}
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