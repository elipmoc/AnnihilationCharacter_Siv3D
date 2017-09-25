#include "EnemyAction\EnemyAction2.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::Move2Action;
	using  elipmocframework::WaitAction;

	std::unique_ptr<elipmocframework::ActionBase> EnemyAction2::GenerateEnemyAction(
		//開始地点
		const siv::Vec2&,
		//中間地点
		const siv::Vec2& stopPos,
		//退散地点
		const siv::Vec2&,
		const int 
	)const {
		return
			Move2Action::Create(stopPos);
	}
}
