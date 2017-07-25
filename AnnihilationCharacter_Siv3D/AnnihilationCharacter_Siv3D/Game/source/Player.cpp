#include "Player.hpp"
#include "TerrainControl.hpp"

namespace game {


	//移動アクション
	void Player::Move(const std::unique_ptr<TerrainControl>& terrainControl) {		

		//着地判定
		if (
				m_underLane!=-1 && 
				GetUnderY() >= terrainControl->GetTerrainY(m_underLane) &&
				(terrainControl->IsExistTerrainFromX(GetUnderX()-15,m_underLane) || terrainControl->IsExistTerrainFromX(GetUnderX()+15, m_underLane))
			) {
			m_jumpCount = 0;
			SetUnderY(terrainControl->GetTerrainY(m_underLane));
			m_yv = 0;
			if (siv::Input::KeyDown.clicked && m_underLane != 0)
				m_underLane--;
		}

		else {
			//次の足元になるレーンを決定
			int i;
			for (i = TerrainControl::LANE_NUM - 1; i >= 0; i--)
				if (GetUnderY() <= terrainControl->GetTerrainY(i)) {
					m_underLane = i;
					break;
				}
			if (i == -1)m_underLane = -1;
		}
		//ジャンプ
		if (siv::Input::KeySpace.clicked &&m_jumpCount < 2) {
			m_yv = -10;
			m_jumpCount++;
		}

		//重力の影響
		m_yv += m_g;

		//左右移動
		if (siv::Input::KeyRight.pressed)
			SetPos({ GetPos().x + speed, GetPos().y });
		if (siv::Input::KeyLeft.pressed)
			SetPos({ GetPos().x - speed, GetPos().y });

		//見えない壁判定
		if (GetUnderX() < 15)
			SetUnderX(15);
		else if (GetUnderX() > siv::Window::Size().x-15)
			SetUnderX(siv::Window::Size().x-15);

		//座標更新
		SetPos({ GetPos().x,GetPos().y + m_yv });
	}

	void Player::Update2(const std::unique_ptr<TerrainControl>& terrainControl) {
		elipmocframework::FontObject::Update();
		Move(terrainControl);
		circle.setPos(GetUnderX(), GetUnderY()).draw(siv::Palette::Red);
	}
}