#pragma once
namespace game {
	class ParticleBase;
	class ParticleList {
		siv::Array<std::unique_ptr<ParticleBase>> m_particles;
	public:
		template<class ParticleType,class ...Args>
		void CreateParticle(Args&& ...args) {
			m_particles.push_back(std::make_unique<ParticleType>(args...));
		}
		ParticleList()=default;
		~ParticleList();
		void Update();
		void Draw()const;
	};
}