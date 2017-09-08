#include "EnemyAction\TestEnemyAction.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using  elipmocframework::WaitAction;

	std::unique_ptr<elipmocframework::ActionBase> TestEnemyAction::GenerateEnemyAction(
		//�J�n�n�_
		const siv::Vec2&,
		//���Ԓn�_
		const siv::Vec2& stopPos,
		//�ގU�n�_
		const siv::Vec2& endPos,
		const int waitTime
	)const{
		return elipmocframework::ScaleAction::Create(1, 30) <<
			MoveAction::Create(endPos, 50) <<
			WaitAction::Create(waitTime)<<
			MoveAction::Create(stopPos, 180);
	}
}
