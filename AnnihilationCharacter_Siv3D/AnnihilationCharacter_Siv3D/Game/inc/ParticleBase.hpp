#pragma once
#include <memory>
namespace game {
	class ParticleFontObject;
	class ParticleBase {

		siv::Array<std::unique_ptr<ParticleFontObject>> m_particleFobjList;

		const siv::Font m_font;
		const siv::String m_text;
		const siv::Vec2 m_pos;
		//パーティクルクラス自身の生存時間
		int m_lifeTime;
		//粒子生存時間
		const int m_particleLifeTime;
		//一度に放出する粒子の数
		const int m_particleNum;
		//初速度
		const double m_speed;
		//加速度
		const double m_vspeed;
		//粒子の色
		const siv::Color m_color;
		//加速透過度
		const double m_vopacity;
		//発火の間隔
		const int m_fireInterval;

		const siv::Vec2 m_g;


	public:

		ParticleBase(
			const siv::String& text, const siv::Vec2& pos,
			const int lifeTime, const int particleLifeTime, const int particleNum,
			const double speed, const double vspeed, const siv::Color& color,
			const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g = {0,0})noexcept;

		static std::unique_ptr<ParticleBase> Create(
			const siv::String& text, const siv::Vec2& pos,
			const int lifeTime, const int particleLifeTime, const int particleNum,
			const double speed, const double vspeed, const siv::Color& color,
			const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g = {0,0}
			) {
			return std::make_unique<ParticleBase>(text,pos,lifeTime,particleLifeTime,particleNum,speed,vspeed,color,vopacity,fireInterval,size,g);
		}

		~ParticleBase();

		bool IsCanDelete() const noexcept{ return m_lifeTime<=0; }

		void Init() {
		}

		void Update();
		void Draw() const;
	private:
		//発火
		virtual void Fire();


	};
}