#include "EnemyAction\EnemyAction2.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::Move2Action;
	using  elipmocframework::WaitAction;

	std::unique_ptr<elipmocframework::ActionBase> EnemyAction2::GenerateEnemyAction(
		//�J�n�n�_
		const siv::Vec2&,
		//���Ԓn�_
		const siv::Vec2& stopPos,
		//�ގU�n�_
		const siv::Vec2&,
		const int 
	)const {
		return
			Move2Action::Create(stopPos);
	}
}
