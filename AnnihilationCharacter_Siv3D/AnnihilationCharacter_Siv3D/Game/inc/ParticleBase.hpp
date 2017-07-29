#pragma once
namespace game {
	class ParticleBase {
		int m_lifeTime;
		//”­‰Î‚ÌŠÔŠu
		int m_fireInterval;
	public:

		ParticleBase(int fireInterval,int lifeTime):m_lifeTime(lifeTime),m_fireInterval(fireInterval){}

		int GetLifeTime() const{ return m_lifeTime; }

		void BaseInit() {
			Init();
		}

		void BaseUpdate() {
			Update();
			m_lifeTime--;
		}
		void BaseDraw() const{
			Draw();
		}
	protected:
		virtual void Init() = 0;
		virtual void Draw()const=0;
		virtual void Update()=0;
		//”­‰Î
		virtual void Fire() = 0;


	};
}