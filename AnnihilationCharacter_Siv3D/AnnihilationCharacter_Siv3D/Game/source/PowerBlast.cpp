#include "PowerBlast.hpp"
#include"BulletList.hpp"

namespace game {
	PowerBlast::PowerBlast()
		:m_bulletList(std::make_unique<BulletList>(30))
	{
	}

	PowerBlast::~PowerBlast() = default;

	void PowerBlast::Start(const siv::Vec2& pos)
	{
	}
	void PowerBlast::Update()
	{
	}
	void PowerBlast::Draw() const
	{
	}
}