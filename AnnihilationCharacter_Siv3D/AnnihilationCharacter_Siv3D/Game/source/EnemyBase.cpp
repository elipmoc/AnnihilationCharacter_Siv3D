#include "EnemyBase.hpp"
#include "BulletList.hpp"

namespace game {
	EnemyBase::EnemyBase(const size_t barrageSize, const siv::Vec2 & startPos, const siv::Vec2 & stopPos, const siv::Vec2 & endPos, const int fontSize)
		:FontObject(fontSize),m_startPos(startPos),m_stopPos(stopPos),m_endPos(endPos),m_barrage(std::make_unique<BulletList>(barrageSize))
	{}

	EnemyBase::~EnemyBase()
	{
	}
	;
}
