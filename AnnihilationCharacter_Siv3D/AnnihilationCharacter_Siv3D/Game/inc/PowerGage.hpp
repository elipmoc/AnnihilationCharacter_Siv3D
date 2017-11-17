#pragma once

namespace game {

	//�擾�����͂��ǂꂭ�炢���������Q�[�W�̃N���X
	class PowerGage {
		siv::Rect m_rect;
		const size_t m_maxPowerNum;
	public:
		PowerGage(size_t maxPowerNum):m_maxPowerNum ( maxPowerNum) {
			
			//�܂��������Ă��Ȃ�
			m_rect.setPos(300, 20);
			
		}
		void Draw(size_t powerNum) {
			//�܂��������Ă��Ȃ�
			m_rect.setSize(200*powerNum /m_maxPowerNum, 20);
			m_rect.draw(siv::Palette::Orange);
			
		}

	};

}