#pragma once

namespace game {

	//取得した力がどれくらいかを示すゲージのクラス
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
			if (powerNum > m_maxPowerNum)
				powerNum = m_maxPowerNum;
			m_rect.setSize(250*powerNum /m_maxPowerNum, 20);
			m_rect.draw(siv::Palette::Orange);
			m_font(L"パワー  :").draw({ 290, 0 }, siv::Palette::Orange);
		}

	};

}