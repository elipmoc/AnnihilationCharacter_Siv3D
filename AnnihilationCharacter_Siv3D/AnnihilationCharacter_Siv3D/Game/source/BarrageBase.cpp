#include "BarrageBase.hpp"
#include "BulletList.hpp"

namespace game {

	BarrageBase::BarrageBase(const size_t bulletSize)
		:m_bulletList(std::make_unique<BulletList>(bulletSize))
	{}

	BarrageBase::~BarrageBase()
	{
	}
}