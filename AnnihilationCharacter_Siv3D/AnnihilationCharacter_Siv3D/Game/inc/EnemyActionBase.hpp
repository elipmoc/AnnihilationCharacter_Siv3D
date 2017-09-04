#pragma once
#include <memory>

namespace elipmocframework {
	class ActionBase;
}

namespace game {
	class EnemyActionBase {
	public :
		virtual std::unique_ptr<elipmocframework::ActionBase> GenerateEnemyAction(
			//�J�n�n�_
			const siv::Vec2& startPos,
			//���Ԓn�_
			const siv::Vec2& stopPos,
			//�ގU�n�_
			const siv::Vec2& endPos,
			//���ԑҋ@�n�_
			const int waitTime
		) const= 0;
	};

}