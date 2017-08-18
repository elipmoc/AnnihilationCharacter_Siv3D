#pragma once
#include <memory>

namespace elipmocframework {
	class ActionBase;
}

namespace game {
	class EnemyActionBase {
	public :
		virtual std::unique_ptr<elipmocframework::ActionBase> GenerateEnemyAction(
			//開始地点
			const siv::Vec2& startPos,
			//中間地点
			const siv::Vec2& stopPos,
			//退散地点
			const siv::Vec2& endPos
		) const= 0;
	};

}