#include "Bullet.hpp"
#include "CollisionCircle.hpp"

namespace game {

	Bullet::Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv)
		:elipmocframework::FontObject(L"�e", 20), m_speedv(speedv), m_vspeedv(vspeedv),
		m_colli(std::make_unique<CollisionCircle>(GetRefPos(), 
			[this](const CollisionID id) {
				if (id == CollisionID::PlayerID || id == CollisionID::BarrierID)this->Delete();
			}))
	{
		m_colli->SetR(10);
		m_colli->SetCollisionID(CollisionID::EnemyBulletID);
		SetPos(pos);
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
		//��ʊO�ɏo����폜
		if (
			GetPos().x<-10 ||
			GetPos().x>siv::Window::Size().x + 10 ||
			GetPos().y<-10 ||
			GetPos().y>siv::Window::Size().y + 10
			)
			Delete();

		m_colli->DoColliQueue();
		elipmocframework::FontObject::Update();
		SetPos(GetPos() + m_speedv);
		m_speedv += m_vspeedv;
	}

}