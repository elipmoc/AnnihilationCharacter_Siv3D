#include "EnemyAction\TestEnemyAction.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using  elipmocframework::WaitAction;

	std::unique_ptr<elipmocframework::ActionBase> TestEnemyAction::GenerateEnemyAction(
		//開始地点
		const siv::Vec2&,
		//中間地点
		const siv::Vec2& stopPos,
		//退散地点
		const siv::Vec2& endPos,
		const int waitTime
	)const{
		return 
			MoveAction::Create(endPos, 50) <<
			WaitAction::Create(waitTime)<<
			MoveAction::Create(stopPos, 180);
	}
}
