#pragma once

namespace game {

	//�擾�����͂��ǂꂭ�炢���������Q�[�W�̃N���X
	class PowerGage {
		siv::Rect m_rect;
		const siv::Font m_font;
		const size_t m_maxPowerNum;
	public:
		PowerGage(size_t maxPowerNum):
			m_maxPowerNum ( maxPowerNum),m_font(20){
			m_rect.setPos(410, 10);
			
		}
		void Draw(size_t powerNum) {
			m_rect.setSize(250*powerNum /m_maxPowerNum, 20);
			m_rect.draw(siv::Palette::Orange);
			m_font(L"�p���[  :").draw({ 290, 0 }, siv::Palette::Orange);
		}

	};

}