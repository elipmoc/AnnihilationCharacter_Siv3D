#pragma once

namespace game {

	class BossHpGage {
		const size_t m_maxhp;
		siv::Rect rect;
	public:
		BossHpGage(size_t maxhp):m_maxhp(maxhp) {
			rect.setPos(530, 80);
			rect.setSize(0, 0);
		}

		void SetSizeFromHp(size_t hp) {
			rect.setSize(150 * hp / m_maxhp, 5);
		}

		void Draw()const {
			rect.draw(siv::Palette::Red);
		}
	};

}