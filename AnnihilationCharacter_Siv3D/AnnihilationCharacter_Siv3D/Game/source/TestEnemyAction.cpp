#include "TestEnemyAction.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using siv::Vec2;

	std::unique_ptr<elipmocframework::ActionBase> TestEnemyAction::GenerateEnemyAction(
		//開始地点
		const siv::Vec2& startPos,
		//中間地点
		const siv::Vec2& stopPos,
		//退散地点
		const siv::Vec2& endPos
	)const{
		return elipmocframework::ScaleAction::Create(1, 30) <<
			MoveAction::Create(endPos, 50) <<
			MoveAction::Create(stopPos, 180);
	}
}
