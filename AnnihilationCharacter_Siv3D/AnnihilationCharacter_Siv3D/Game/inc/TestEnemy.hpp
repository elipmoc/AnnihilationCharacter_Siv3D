#pragma once
#include "EnemyActionBase.hpp"

namespace game {
	class TestEnemyAction :public EnemyActionBase {
	public:

		TestEnemyAction(std::unique_ptr<elipmocframework::FontObject>& enemyFont,
			const siv::Vec2 & startPos,
			const siv::Vec2 & stopPos,
			const siv::Vec2 & endPos);

		virtual void Update()override;
	};
}