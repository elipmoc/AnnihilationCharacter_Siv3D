#pragma once
#include <memory>
#include "ObjectPool.hpp"
#include "ParticleFontObject.hpp"
namespace elipmocframework {
	class ParticleBase {
		ObjectPool<ParticleFontObject> m_particleFobjList;


		const siv::Font m_font;
		const siv::String m_text;
		siv::Vec2 m_pos;
		//パーティクルクラス自身の生存時間
		const int m_lifeTime;
		//生存時間カウント用
		int m_lifeCount;
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
			const siv::String& text,
			const int lifeTime, const int particleLifeTime, const int particleNum,
			const double speed, const double vspeed, const siv::Color& color,
			const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g = {0,0})noexcept
			:m_text(text), m_lifeTime(lifeTime), m_particleLifeTime(particleLifeTime), m_particleNum(particleNum), m_speed(speed),
			m_vspeed(vspeed), m_color(color), m_vopacity(vopacity), m_fireInterval(fireInterval), m_font(size), m_g(g), m_particleFobjList(6000) {}


		bool IsCanDelete() const noexcept{ return m_lifeCount<=0; }

		void Start(const siv::Vec2& pos) {
			m_particleFobjList.DeleteAll();
			m_pos = pos; 
			m_lifeCount = m_lifeTime; 
		}

		void Update() {
			//寿命が来た粒子を削除する
			elipmocframework::DeleteIf(m_particleFobjList, [](const auto& particle) {
				return particle.IsCanDelete();
			});

			//粒子更新
			for (auto&& item : m_particleFobjList)
				item.Update();
			//発火するタイミングなら発火させる
			if (m_lifeCount%m_fireInterval == 0)
				Fire();

			m_lifeCount--;
		}

		void Draw()const {
			for (const auto& item : m_particleFobjList)
				item.Draw();
		}

	private:
		//発火
		virtual void Fire() {
			for (size_t i = 0; i < m_particleNum; i++) {
				double angle = siv::Math::Radians(siv::Random(0, 359));
				siv::Vec2 e = { siv::Math::Cos(angle),siv::Math::Sin(angle) };
				m_particleFobjList.New(m_text, m_color, m_font, m_pos, m_particleLifeTime, e*m_speed, e*m_vspeed, m_vopacity, m_g);
			}
		}


	};
}