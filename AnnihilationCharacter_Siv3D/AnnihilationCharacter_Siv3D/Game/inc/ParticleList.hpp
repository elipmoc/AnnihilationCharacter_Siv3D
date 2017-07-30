#pragma once
namespace game {
	class ParticleBase;
	class ParticleList {
		siv::Array<std::unique_ptr<ParticleBase>> m_particles;
	public:
		void AddParticle(std::unique_ptr<ParticleBase>&&);
		ParticleList()=default;
		~ParticleList();
		void Update();
		void Draw()const;
	};
}