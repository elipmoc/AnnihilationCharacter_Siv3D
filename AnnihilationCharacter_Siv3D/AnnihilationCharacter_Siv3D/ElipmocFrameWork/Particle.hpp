#pragma once
#include <memory>
#include "ObjectPool.hpp"
#include "ParticleFontObject.hpp"
namespace elipmocframework {

	struct ParticleState {
		//�\�����镶��
		siv::String text;
		//�\�����镶���T�C�Y
		size_t fontSize=20;
		//�p�[�e�B�N���N���X���g�̐�������
		int lifeTime=0;
		//���q��������
		int particleLifeTime=0;
		//��x�ɕ��o���闱�q�̐�
		size_t particleNum=0;
		//���݂ł��闱�q�̐�
		size_t particleMaxNum=100;
		//�����x
		double speed=0;
		//�����x�u����
		double speedBlur = 0;
		//�����x
		double vspeed=0;
		//���q�̐F
		siv::Color color=siv::Palette::White;
		//�������ߓx
		double vopacity=0;
		//���΂̊Ԋu
		int fireInterval=99999;
		//�d�͉����x�̐ݒ�
		siv::Vec2 g = {0,0};

	};

	class Particle {
		ObjectPool<ParticleFontObject> m_particleFobjList;
		const ParticleState m_state;
		siv::Vec2 m_pos;
		//�\������t�H���g�I�u�W�F�N�g
		const siv::Font m_font;
		//�������ԃJ�E���g�p
		int m_lifeCount;


	public:

		Particle(const ParticleState state)noexcept
			:m_state(state), m_font(state.fontSize), m_particleFobjList(state.particleMaxNum) {}


		bool IsCanDelete() const noexcept{ return m_lifeCount<=0; }

		void Start(const siv::Vec2& pos) {
			m_particleFobjList.DeleteAll();
			m_pos = pos; 
			m_lifeCount = m_state.lifeTime; 
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
			if (m_lifeCount%m_state.fireInterval == 0)
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
			for (size_t i = 0; i < m_state.particleNum; i++) {

				//�v�[���������ς��ɂȂ����甲����
				if (m_particleFobjList.MaxSize() == m_particleFobjList.Size())
					return;

				double angle = siv::Math::Radians(siv::Random(0, 359));
				siv::Vec2 e = { siv::Math::Cos(angle),siv::Math::Sin(angle) };
				m_particleFobjList.New(
					m_state.text, m_state.color, m_font, m_pos, m_state.particleLifeTime, e*(m_state.speed+siv::Random(-1,1)*m_state.speedBlur), e*m_state.vspeed, m_state.vopacity, m_state.g);
			}
		}


	};
}