#include "TestEnemy.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using siv::Vec2;

	TestEnemyAction::TestEnemyAction(
		std::unique_ptr<elipmocframework::FontObject>& enemyFont,
		const siv::Vec2 & startPos,
		const siv::Vec2 & stopPos,
		const siv::Vec2 & endPos):EnemyActionBase(enemyFont,startPos,stopPos,endPos) {

		GetEnemyFont().SetPos( startPos );
		GetEnemyFont().SetColor(siv::Palette::Yellow);
		//‚Ä‚«ˆÚ“®
		GetEnemyFont().AddAction(
			elipmocframework::ScaleAction::Create(1, 30)<<
			MoveAction::Create(endPos, 50) <<
			MoveAction::Create(stopPos, 180) 
			
		);
	}

	void TestEnemyAction::Update()
	{
	}
}
