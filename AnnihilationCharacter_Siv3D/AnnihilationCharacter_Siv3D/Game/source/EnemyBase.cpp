#include "EnemyBase.hpp"
#include "BarrageBase.hpp"

namespace game {
	EnemyBase::EnemyBase(
		std::unique_ptr<BarrageBase> &&barrage,
		const siv::Vec2 & startPos, 
		const siv::Vec2 & stopPos,
		const siv::Vec2 & endPos, 
		const int fontSize)
		:FontObject(fontSize),
		m_startPos(startPos),
		m_stopPos(stopPos),
		m_endPos(endPos),
		m_barrage(std::move(barrage))
	{}

	void EnemyBase::Draw() const
	{
		FontObject::Draw();
		m_barrage->Draw();
	}

	EnemyBase::~EnemyBase()
	{
	}
}
