#include "Player.hpp"
#include "TerrainControl.hpp"
#include "ParticleList.hpp"
#include "PlayerDeadParticle.hpp"
#include "CollisionCircle.hpp"

namespace game {


	//移動アクション
	void Player::Move(const std::unique_ptr<TerrainControl>& terrainControl) {		

		//落下判定
		if (GetPos().y>siv::Window::Size().y+40) {
			PlayerDead();
		}

		//着地判定
		if (
				m_underLane!=-1 && 
				GetUnderY() >= terrainControl->GetTerrainY(m_underLane) &&
				(terrainControl->IsExistTerrainFromX(GetPos().x-15,m_underLane) || terrainControl->IsExistTerrainFromX(GetPos().x+15, m_underLane))
			) {
			m_jumpCount = 0;
			SetUnderY(terrainControl->GetTerrainY(m_underLane));
			m_yv = 0;
			if (siv::Input::KeyDown.clicked && m_underLane != -1)
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
		if (GetPos().x < 15)
			SetPosX(15);
		else if (GetPos().x > siv::Window::Size().x-15)
			SetPosX(siv::Window::Size().x-15);

		//座標更新
		SetPos({ GetPos().x,GetPos().y + m_yv });
	}

	void Player::PlayerDead(){
		if(m_hp!=0)m_hp--;
		m_deadParticle->Set(GetPos());
		SetPos({ 0,0 });
		m_yv = 0;
	}

	Player::Player() :circle(3), m_deadParticle(CreatePlayerDeadParticleList()),
		m_colliObject(std::make_unique<CollisionCircle>(GetRefPos(), [this](CollisionID id) {if(id==CollisionID::EnemyID)this->PlayerDead(); }))
	{
		m_colliObject->SetR(10);
		m_colliObject->SetCollisionID(CollisionID::PlayerID);

	}

	Player::~Player(){}

	void Player::Update2(const std::unique_ptr<TerrainControl>& terrainControl) {
		elipmocframework::FontObject::Update();
		Move(terrainControl);
		m_colliObject->DoColliQueue();
		m_deadParticle->Update();
		m_deadParticle->Draw();
		circle.setPos(GetPos().x,GetUnderY()).draw(siv::Palette::Red);
	}
}