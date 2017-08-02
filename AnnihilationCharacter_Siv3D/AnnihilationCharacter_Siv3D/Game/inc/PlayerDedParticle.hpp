#pragma once
#include <memory>
namespace elipmocframework {
	class ParticleList;
}

namespace game {

	std::unique_ptr < elipmocframework::ParticleList > CreatePlayerDedParticleList();

}