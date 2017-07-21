#include "Player.hpp"
#include "TerrainControl.hpp"

namespace game {


	//ˆÚ“®ƒAƒNƒVƒ‡ƒ“
	void Player::Move(const std::unique_ptr<TerrainControl>& terrainControl) {
		SetPos({ GetPos().x,GetPos().y + m_yv });
		m_yv += m_g;
		if (GetUnderY() >= terrainControl->GetTerrainY(0)) {
			m_jumpCount = 0;
			SetUnderY(terrainControl->GetTerrainY(0));
			m_yv = 0;
		}
		if (siv::Input::KeySpace.clicked &&m_jumpCount < 2) {
			m_yv = -10;
			m_jumpCount++;
		}
		if (siv::Input::KeyRight.pressed)
			SetPos({ GetPos().x + speed, GetPos().y });
		if (siv::Input::KeyLeft.pressed)
			SetPos({ GetPos().x - speed, GetPos().y });
	}

	void Player::Update2(const std::unique_ptr<TerrainControl>& terrainControl) {
		elipmocframework::FontObject::Update();
		Move(terrainControl);
		circle.setPos(GetPos().x, GetUnderY()).draw(siv::Palette::Red);
	}
}