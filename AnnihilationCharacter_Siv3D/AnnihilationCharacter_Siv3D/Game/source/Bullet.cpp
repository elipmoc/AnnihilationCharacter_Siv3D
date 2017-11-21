#include "Bullet.hpp"
#include "CollisionCircle.hpp"

namespace game {

	Bullet::Bullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv)
		:elipmocframework::FontObject(L"íe", 17), m_speedv(speedv), m_vspeedv(vspeedv),
		m_colli(std::make_unique<CollisionCircle>(GetRefPos(), 
			[this](const CollisionID id) {
				if (id == CollisionID::PlayerID || id == CollisionID::BarrierID)this->Delete();
			}))
	{
		m_colli->SetR(9);
		m_colli->SetCollisionID(CollisionID::EnemyBulletID);
		SetPos(pos);
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
		//âÊñ äOÇ…èoÇΩÇÁçÌèú
		if (
			GetPos().x<-10 ||
			GetPos().x>siv::Window::Size().x + 10 ||
			GetPos().y<-10 ||
			GetPos().y>siv::Window::Size().y + 10
			)
			Delete();

		m_colli->DoColliQueue();
		if (m_func != nullptr)
			m_func(*this);
		elipmocframework::FontObject::Update();
		SetPos(GetPos() + m_speedv);
		m_speedv += m_vspeedv;
		m_counter++;

	}

}