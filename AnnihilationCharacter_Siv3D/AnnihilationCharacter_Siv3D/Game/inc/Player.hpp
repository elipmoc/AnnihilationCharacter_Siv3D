#pragma once
#include "FontObject.hpp"
#include <memory>

namespace elipmocframework {
	class ParticleList;
}

namespace game {

	class TerrainControl;
	class CollisionCircle;
	class Player :public elipmocframework::FontObject {
		//���G����
		static constexpr int MUTEKI_TIME = 100;

		//���G���ԃJ�E���g
		int m_mutekiCount=0;

		//���S���̃p�[�e�B�N��
		std::unique_ptr<elipmocframework::ParticleList> m_deadParticle;

		//�����蔻��object
		std::unique_ptr<CollisionCircle> m_colliObject;

		//hp
		size_t m_hp=6;

		//�ړ��X�s�[�h
		static constexpr double speed=3.5;
		//�d�͉����x
		static constexpr double m_g=0.3;
		//Y�̑��x
		double m_yv=0;
		//�W�����v�����񐔋L�^
		int m_jumpCount=0;
		//�f�o�b�N�p
		siv::Circle circle;

		//�����̑����ɂ���n�`���[��
		int m_underLane = 2;

		//�ړ��A�N�V����
		void Move(const std::unique_ptr<TerrainControl>&);

		//��l�����S����
		void PlayerDead();

		//��l���������S����
		void PlayerFallDead();

		//��l���̑�����Y�𓾂�
		double GetUnderY()const {
			return GetPos().y + 15;
		}


		//��l����X���Z�b�g����
		void SetPosX(double x) {
			SetPos({ x,GetPos().y });
		}

		//��l���̑����̍������Z�b�g����
		void SetUnderY(double y) {
			SetPos({ GetPos().x,y - 15 });
		}

	public:

		size_t GetHp()const noexcept { return m_hp; }
		Player();
		~Player();



		void Update2(const std::unique_ptr<TerrainControl>&);
	};

}