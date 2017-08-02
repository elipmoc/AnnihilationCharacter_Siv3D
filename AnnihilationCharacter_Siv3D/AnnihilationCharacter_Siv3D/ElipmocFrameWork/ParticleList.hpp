#pragma once
#include "ObjectPool.hpp"
#include "Particle.hpp"

namespace elipmocframework {

	class ParticleList {
		ObjectPool<Particle> m_particles;
	public:
		ParticleList(const size_t size,const ParticleState& state) :m_particles(size) {
			for (size_t i = 0; i < m_particles.MaxSize(); i++)
				m_particles.New(state);
			for (size_t i = 0; i < m_particles.MaxSize(); i++)
				m_particles.NoCallDeleteAt(0);
		}

		void Set(const siv::Vec2& pos) {
			m_particles.NoCallNew().Start(pos);
		}


		void Update() {
			NoCallDeleteIf(
				m_particles, [](const Particle& particle) {
				return particle.IsCanDelete();
			});
			for (auto&& item : m_particles)
				item.Update();
		}

		void Draw()const {
			for (auto&& item : m_particles)
				item.Draw();

		}
	};
}