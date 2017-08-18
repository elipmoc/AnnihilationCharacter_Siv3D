#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class EnemyActionBase {

		std::unique_ptr<elipmocframework::FontObject>& m_enemyFont;

		//�J�n�n�_
		const siv::Vec2 m_startPos;
		//���Ԓn�_
		const siv::Vec2 m_stopPos;
		//�ގU�n�_
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