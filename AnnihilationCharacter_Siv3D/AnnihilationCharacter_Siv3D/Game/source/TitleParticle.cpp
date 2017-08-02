#include "TitleParticle.hpp"
#include "ParticleList.hpp"

namespace game {
	using elipmocframework::ParticleList;
	using elipmocframework::ParticleState;

	TitleParticle::TitleParticle()
	{
		elipmocframework::ParticleState state;
		state.lifeTime = 200;
		state.particleLifeTime = 200;
		state.particleNum = 10;
		state.particleMaxNum = 10;
		state.speed = 2;
		state.vspeed = 0.0001;
		state.fireInterval = 100;
		state.text = L"è¡";
		state.vopacity = -2.5;
		m_particle1=std::make_unique<ParticleList>(40, state);
		state.text = L"ñ≈";
		m_particle2 = std::make_unique<ParticleList>(40, state);
	}
	TitleParticle::~TitleParticle()
	{
	}
	void TitleParticle::Update()
	{
		if (siv::Random(1, 100) == 5)
			if (siv::Random(1, 2) == 1)
				m_particle1->Set({ siv::Random(0,700),siv::Random(0,580) });
			else
				m_particle2->Set({ siv::Random(0,700),siv::Random(0,580) });
		m_particle1->Update();
		m_particle2->Update();

	}
	void TitleParticle::Draw() const
	{
		m_particle1->Draw();
		m_particle2->Draw();
	}
}
