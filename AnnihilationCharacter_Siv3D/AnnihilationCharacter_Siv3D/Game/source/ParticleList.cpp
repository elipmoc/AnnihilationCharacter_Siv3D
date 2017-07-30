#include "ParticleList.hpp"
#include "ParticleBase.hpp"

namespace game {
	void ParticleList::AddParticle(std::unique_ptr<ParticleBase>&& particle)
	{
		m_particles.push_back(std::move(particle));
	}

	ParticleList::~ParticleList()
	{
	}


	void ParticleList::Update()
	{
		auto&& tail_itr=
			std::remove_if(m_particles.begin(), m_particles.end(), [](const std::unique_ptr<ParticleBase>& particle){
			return particle->IsCanDelete();
		});
		m_particles.erase(tail_itr, m_particles.end());
		for (auto&& item : m_particles)
			item->Update();
	}

	void ParticleList::Draw()const
	{
		for (auto&& item : m_particles)
			item->Draw();
	}
}
