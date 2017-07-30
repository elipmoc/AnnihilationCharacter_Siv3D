#include "ParticleBase.hpp"

namespace game {


	ParticleBase::ParticleBase(
		const siv::String& text, const siv::Vec2& pos,
		const int lifeTime, const int particleLifeTime, const int particleNum,
		const double speed, const double vspeed, const siv::Color& color,
		const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g)noexcept
		:m_text(text), m_pos(pos), m_lifeTime(lifeTime), m_particleLifeTime(particleLifeTime), m_particleNum(particleNum), m_speed(speed),
		m_vspeed(vspeed), m_color(color), m_vopacity(vopacity), m_fireInterval(fireInterval), m_font(size),m_g(g),m_particleFobjList(6000){}

	ParticleBase::~ParticleBase()
	{
	}

	void ParticleBase::Update() {
		siv::PutText(siv::Format(siv::Profiler::FPS())).at({ 200,50 });
		siv::PutText(siv::Format(m_particleFobjList.Size())).at({200,100});
		//寿命が来た粒子を削除する
		elipmocframework::DeleteIf(m_particleFobjList, [](const auto& particle) {
			return particle.IsCanDelete();
		});

		//粒子更新
		for (auto&& item : m_particleFobjList)
			item.Update();
		//発火するタイミングなら発火させる
		if (m_lifeTime%m_fireInterval == 0)
			Fire();

		m_lifeTime--;
	}

	void ParticleBase::Draw()
	{
		for (const auto& item : m_particleFobjList)
			item.Draw();
	}

	void ParticleBase::Fire()
	{
		for (size_t i = 0; i < m_particleNum; i++) {
			double angle = siv::Math::Radians(siv::Random(0, 359));
			siv::Vec2 e = { siv::Math::Cos(angle),siv::Math::Sin(angle) };
			m_particleFobjList.New(m_text, m_color, m_font, m_pos, m_particleLifeTime, e*m_speed, e*m_vspeed, m_vopacity,m_g);
		}
	}
}
