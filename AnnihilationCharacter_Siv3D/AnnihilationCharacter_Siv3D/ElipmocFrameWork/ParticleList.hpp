#pragma once
#include "ObjectPool.hpp"
#include "ParticleBase.hpp"

namespace elipmocframework {

	class ParticleList {
		ObjectPool<ParticleBase> m_particles;
	public:
		template<class... Args>
		ParticleList(const size_t size, Args&& ...args) :m_particles(size) {
			for (size_t i = 0; i < m_particles.MaxSize(); i++)
				m_particles.New(std::forward<Args>(args)...);
			for (size_t i = 0; i < m_particles.MaxSize(); i++)
				m_particles.NoCallDeleteAt(0);
		}

		void Set(const siv::Vec2& pos) {
			m_particles.NoCallNew().Start(pos);
		}


		void Update() {
			NoCallDeleteIf(
				m_particles, [](const ParticleBase& particle) {
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