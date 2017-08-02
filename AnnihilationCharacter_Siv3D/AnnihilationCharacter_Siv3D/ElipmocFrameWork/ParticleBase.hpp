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
		//�p�[�e�B�N���N���X���g�̐�������
		const int m_lifeTime;
		//�������ԃJ�E���g�p
		int m_lifeCount;
		//���q��������
		const int m_particleLifeTime;
		//��x�ɕ��o���闱�q�̐�
		const int m_particleNum;
		//�����x
		const double m_speed;
		//�����x
		const double m_vspeed;
		//���q�̐F
		const siv::Color m_color;
		//�������ߓx
		const double m_vopacity;
		//���΂̊Ԋu
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
			//�������������q���폜����
			elipmocframework::DeleteIf(m_particleFobjList, [](const auto& particle) {
				return particle.IsCanDelete();
			});

			//���q�X�V
			for (auto&& item : m_particleFobjList)
				item.Update();
			//���΂���^�C�~���O�Ȃ甭�΂�����
			if (m_lifeCount%m_fireInterval == 0)
				Fire();

			m_lifeCount--;
		}

		void Draw()const {
			for (const auto& item : m_particleFobjList)
				item.Draw();
		}

	private:
		//����
		virtual void Fire() {
			for (size_t i = 0; i < m_particleNum; i++) {
				double angle = siv::Math::Radians(siv::Random(0, 359));
				siv::Vec2 e = { siv::Math::Cos(angle),siv::Math::Sin(angle) };
				m_particleFobjList.New(m_text, m_color, m_font, m_pos, m_particleLifeTime, e*m_speed, e*m_vspeed, m_vopacity, m_g);
			}
		}


	};
}