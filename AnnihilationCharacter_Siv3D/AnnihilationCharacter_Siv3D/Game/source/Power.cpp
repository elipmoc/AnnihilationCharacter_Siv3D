#include "Power.hpp"
#include "CollisionCircle.hpp"

namespace game {

	Power& Power::operator=(Power&&) = default;

	Power::Power(Power &&) = default;

	Power::Power(const siv::Vec2 & pos, const siv::Vec2 & speedv)
		:elipmocframework::FontObject(L"力", 30), m_speedv(speedv),
		m_colli(std::make_unique<CollisionCircle>(GetRefPos(),
			[this](const CollisionID id) {
		if (id == CollisionID::PlayerID)this->Delete();
	}))
	{
		SetColor(siv::Palette::Orange);
		m_colli->SetR(30);
		m_colli->SetCollisionID(CollisionID::PowerID);
		SetPos(pos);
	}

	Power::~Power() = default;

	void Power::Update()
	{
		//画面外に出たら削除
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
	}

}