#pragma once
#include <memory>
namespace elipmocframework {
	class ParticleList;
}

namespace game {
	//タイトル画面のパーティクルを制御するクラス
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