#pragma once
namespace game {
	class ParticleBase {
		int m_lifeTime;
	public:

		ParticleBase(int lifeTime=0):m_lifeTime(lifeTime){}

		int GetLifeTime() const{ return m_lifeTime; }

		void BaseUpdate() {
			Update();
			m_lifeTime--;
		}
		void BaseDraw() const{
			Draw();
		}
	protected:
		virtual void Draw()const=0;
		virtual void Update()=0;


	};
}