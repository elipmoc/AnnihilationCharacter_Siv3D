#include "PowerBlast.hpp"
#include"BulletListCreator.hpp"

namespace game {
	PowerBlast::PowerBlast(const BulletListCreator & bulletListCreator,const siv::Vec2 pos)
		:m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator)),
		m_pos(pos)
	{
	}

	PowerBlast::~PowerBlast() = default;
}