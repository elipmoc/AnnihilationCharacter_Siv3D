#pragma once
#include "PreObjectPool.hpp"
#include "Particle.hpp"

namespace elipmocframework {

	class ParticleList {
		PreObjectPool<Particle> m_particles;
	public:
		ParticleList(const size_t size,const ParticleState& state) :m_particles(size,state) {
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