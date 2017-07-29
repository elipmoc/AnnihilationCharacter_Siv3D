#pragma once
#include "ParticleBase.hpp"
namespace game {
	class PlayerDamageParticle:public ParticleBase {
		virtual void Init()override;
		virtual void Draw()const override;
		virtual void Update()override;
		virtual void Fire()override;

	};
}