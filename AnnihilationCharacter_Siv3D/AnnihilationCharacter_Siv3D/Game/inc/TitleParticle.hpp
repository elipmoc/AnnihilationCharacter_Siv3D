#pragma once
#include <memory>
namespace elipmocframework {
	class ParticleList;
}

namespace game {
	//�^�C�g����ʂ̃p�[�e�B�N���𐧌䂷��N���X
	class TitleParticle {
		std::unique_ptr<elipmocframework::ParticleList> m_particle1;
		std::unique_ptr<elipmocframework::ParticleList> m_particle2;
	public:
		TitleParticle();
		~TitleParticle();
		void Update();
		void Draw()const;
	};
}