#include "ParticleList.hpp"
#include "ParticleBase.hpp"

namespace game {
	ParticleList::~ParticleList()
	{
	}


	void ParticleList::Update()
	{
		auto&& tail_itr=
			std::remove_if(m_particles.begin(), m_particles.end(), [](const std::unique_ptr<ParticleBase>& particle){
			return particle->GetLifeTime() == 0;
		});
		m_particles.erase(tail_itr, m_particles.end());
		for (auto&& item : m_particles)
			item->BaseUpdate();
	}

	void ParticleList::Draw()const
	{
		for (auto&& item : m_particles)
			item->BaseDraw();
	}
}
