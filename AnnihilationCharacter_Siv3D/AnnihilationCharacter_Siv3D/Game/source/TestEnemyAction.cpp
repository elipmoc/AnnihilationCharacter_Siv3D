#include "TestEnemyAction.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using siv::Vec2;

	std::unique_ptr<elipmocframework::ActionBase> TestEnemyAction::GenerateEnemyAction(
		//�J�n�n�_
		const siv::Vec2& startPos,
		//���Ԓn�_
		const siv::Vec2& stopPos,
		//�ގU�n�_
		const siv::Vec2& endPos
	)const{
		return elipmocframework::ScaleAction::Create(1, 30) <<
			MoveAction::Create(endPos, 50) <<
			MoveAction::Create(stopPos, 180);
	}
}