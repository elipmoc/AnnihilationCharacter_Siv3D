#pragma once

namespace game {

	//取得した力がどれくらいかを示すゲージのクラス
	class PowerGage {
		siv::Rect m_rect;
		const size_t m_maxPowerNum;
	public:
		PowerGage(size_t maxPowerNum):m_maxPowerNum ( maxPowerNum) {
			
			//まだ実装していない
			m_rect.setPos(300, 20);
			
		}
		void Draw(size_t powerNum) {
			//まだ実装していない
			m_rect.setSize(200*powerNum /m_maxPowerNum, 20);
			m_rect.draw(siv::Palette::Orange);
			
		}

	};

}