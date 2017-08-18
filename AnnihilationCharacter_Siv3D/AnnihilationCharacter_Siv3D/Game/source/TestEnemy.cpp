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
		GetEnemyFont().SetText(
			
			L"         ÅQÅQÅQ_Å@Å@\n"
			L"      Å^Å@Å@ Å@ Å_\n"
			L"    Å^Å@ÑüÅ@Å@ Ñü Å_\n"
			L"  Å^Å@ (ÅúÅj ÅiÅúÅj Å_\n"
			L"  |     Åi__êl__Åj      |\n"
			L"  /        ÅøÉm ÅΩ        Å^\n"
			L"  (   Å_Å@Å^ ÅQÉm  | |\n"
			L"   Å_ ÅgÅ@ Å^  ÅQÅQ| |\n"
			L"      Å_ Å^ ÅQÅQÅQ Å^\n"
		);

		GetEnemyFont().SetPos( startPos );
		GetEnemyFont().SetColor(siv::Palette::Yellow);
		//ÇƒÇ´à⁄ìÆ
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
