#include "Player.hpp"
#include "TerrainControl.hpp"
#include "ParticleList.hpp"
#include "PlayerDeadParticle.hpp"
#include "CollisionCircle.hpp"
#include "define.hpp"
#include "Barrier.hpp"

namespace game {


	//移動アクション
	void Player::Move(const std::unique_ptr<TerrainControl>& terrainControl) {		

		//バリア起動
		if (siv::Input::KeyX.clicked && m_barrier->IsBarrier()==false && m_barrierCount!=0) {
			m_barrier->SetBarrier();
			m_barrierCount--;
			siv::SoundAsset(L"バリア").play();
		}

		//落下判定
		if (GetPos().y>siv::Window::Size().y+40) {
			PlayerFallDead();
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
			for (i = LANE_NUM - 1; i >= 0; i--)
				if (GetUnderY() <= terrainControl->GetTerrainY(i)) {
					m_underLane = i;
					break;
				}
			if (i == -1)m_underLane = -1;
			//急速落下
			if (siv::Input::KeyDown.pressed)
				m_yv += 0.3;
		}
		//ジャンプ
		if (m_jumpCount < 3) {
			if (
				(siv::Input::KeyZ.clicked)
				|| (siv::Input::KeyZ.pressed && m_yv >= 0)
				) {
				m_yv = -7;
				m_jumpCount++;
				siv::SoundAsset(L"jump").playMulti();
			}
		}

		//重力の影響
		m_yv += m_g;

		//左右移動
		if (siv::Input::KeyRight.pressed)
			SetPos({ GetPos().x + m_speed, GetPos().y });
		if (siv::Input::KeyLeft.pressed)
			SetPos({ GetPos().x - m_speed, GetPos().y });

		//見えない壁判定
		if (GetPos().x < 15)
			SetPosX(15);
		else if (GetPos().x > siv::Window::Size().x-15)
			SetPosX(siv::Window::Size().x-15);

		//座標更新
		SetPos({ GetPos().x,GetPos().y + m_yv });
	}

	void Player::PlayerDead(){
		if (m_mutekiCount != 0)return;
		if(m_hp!=0)m_hp--;
		m_deadParticle->Set(GetPos());
		SetPos({ 0,0 });
		m_yv = 0;
		m_jumpCount = 0;
		m_mutekiCount = MUTEKI_TIME;
	}

	void Player::PlayerFallDead()
	{
		if (m_hp != 0)m_hp--;
		m_jumpCount = 0;
		m_deadParticle->Set(GetPos());
		SetPos({ 0,0 });
		m_yv = 0;
		m_mutekiCount = MUTEKI_TIME;

	}

	void Player::CollisionCheck(const CollisionID& id)
	{
		if (id == CollisionID::EnemyID || id == CollisionID::EnemyBulletID)
			PlayerDead();
		else if (id == CollisionID::PowerID)
			if(m_powerNum<MAX_POWERNUM)
				m_powerNum++;
			else {
				m_powerNum=0;
			}
	}

	Player::Player() :circle(3), m_deadParticle(CreatePlayerDeadParticleList()),
		m_colliObject(
			std::make_unique<CollisionCircle>(GetRefPos(), 
				[this](CollisionID id) {this->CollisionCheck(id);}
			)
		),
		m_barrier(std::make_unique<Barrier>(GetRefPos()))
	{
		m_colliObject->SetR(5);
		m_colliObject->SetCollisionID(CollisionID::PlayerID);
	}

	Player::~Player(){}

	void Player::Update2(const std::unique_ptr<TerrainControl>& terrainControl) {
		if (m_mutekiCount != 0)m_mutekiCount--;
		elipmocframework::FontObject::Update();
		Move(terrainControl);
		m_barrier->Update();
		m_barrier->Draw();
		m_colliObject->DoColliQueue();
		m_deadParticle->Update();
		m_deadParticle->Draw();
		circle.setPos(GetPos().x,GetUnderY()).draw(siv::Palette::Red);
	}
}