#include "PlayerDeadParticle.hpp"
#include "ParticleList.hpp"

using elipmocframework::ParticleList;
using elipmocframework::ParticleState;

std::unique_ptr<ParticleList> game::CreatePlayerDeadParticleList()
{
	ParticleState state;
	state.color = siv::Palette::Red;
	state.fireInterval = 100;
	state.fontSize = 30;
	state.lifeTime = 100;
	state.particleLifeTime = 100;
	state.particleMaxNum = 15;
	state.particleNum = 15;
	state.speed = 7;
	state.text = L"‚®‚Í‚Á";
	state.vopacity = -3;
	state.vspeed = -0.1;
	return std::make_unique<ParticleList>(3, state);
}
