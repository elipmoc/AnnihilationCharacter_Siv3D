#pragma once
namespace game {
	class ParticleBase {
		int m_lifeTime;
	public:

		ParticleBase(int lifeTime=0):m_lifeTime(lifeTime){}

		int GetLifeTime() { return m_lifeTime; }

		void BaseUpdate() {
			Update();
			m_lifeTime--;
		}
		void BaseDraw() {
			Draw();
		}
	protected:
		virtual void Draw()=0;
		virtual void Update()=0;


	};
}