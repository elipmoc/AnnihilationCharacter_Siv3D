#pragma once

namespace game {

	class BossHpGage {
		int m_maxhp;
		siv::Rect rect;
	public:
		BossHpGage() {
			rect.setPos(500, 60);
			rect.setSize(0, 0);
		}

		void SetMaxHp(int maxhp) {
			m_maxhp = maxhp;
		}

		void SetSizeFromHp(int hp) {
			if (hp < 0)hp = 0;
			rect.setSize(150 * hp / m_maxhp, 5);
		}

		void Draw()const {
			rect.draw(siv::Palette::Red);
		}
	};

}