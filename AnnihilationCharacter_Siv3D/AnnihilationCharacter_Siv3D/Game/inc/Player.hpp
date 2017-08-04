#pragma once
#include "FontObject.hpp"
#include <memory>

namespace elipmocframework {
	class ParticleList;
}

namespace game {

	class TerrainControl;
	class Player :public elipmocframework::FontObject {

		//���S���̃p�[�e�B�N��
		std::unique_ptr<elipmocframework::ParticleList> m_deadParticle;

		//�ړ��X�s�[�h
		static constexpr double speed=3.5;
		//�d�͉����x
		static constexpr double m_g=0.4;
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

		//��l���̑�����Y�𓾂�
		double GetUnderY()const {
			return GetPos().y + 35;
		}

		//��l���̑�����X�𓾂�
		double GetUnderX()const {
			return GetPos().x + 15;
		}

		//��l���̑�����X�𓾂�
		void SetUnderX(double x) {
			SetPos({ x - 15,GetPos().y });
		}

		//��l���̑����̍������Z�b�g����
		void SetUnderY(double y) {
			SetPos({ GetPos().x,y - 35 });
		}

	public:
		Player();
		~Player();



		void Update2(const std::unique_ptr<TerrainControl>&);
	};

}