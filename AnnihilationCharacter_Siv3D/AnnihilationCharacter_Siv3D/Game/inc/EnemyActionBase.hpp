#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class EnemyActionBase {

		std::unique_ptr<elipmocframework::FontObject>& m_enemyFont;

		//開始地点
		const siv::Vec2 m_startPos;
		//中間地点
		const siv::Vec2 m_stopPos;
		//退散地点
		const siv::Vec2 m_endPos;

	protected:
		elipmocframework::FontObject& GetEnemyFont();

	public :
		EnemyActionBase(
			std::unique_ptr<elipmocframework::FontObject>& enemyFont,
			const siv::Vec2& startPos,
			const siv::Vec2& stopPos,
			const siv::Vec2& endPos);

		~EnemyActionBase();

		virtual void Update() = 0;
	};

}