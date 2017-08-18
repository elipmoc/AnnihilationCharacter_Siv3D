#include "EnemyActionBase.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;

	elipmocframework::FontObject & EnemyActionBase::GetEnemyFont()
	{
		return *m_enemyFont.get();
	}

	EnemyActionBase::EnemyActionBase(
		std::unique_ptr<FontObject>& enemyFont,
		const siv::Vec2 & startPos,
		const siv::Vec2 & stopPos,
		const siv::Vec2 & endPos)
		:m_enemyFont(enemyFont),m_startPos(startPos),m_stopPos(stopPos),m_endPos(endPos)
	{
	}
	EnemyActionBase::~EnemyActionBase(){}
}
