#pragma once
#include "FontObject.hpp"

namespace game {
	class EnemyBase :public elipmocframework::FontObject{
	protected:
		//�J�n�n�_
		const siv::Vec2 m_startPos;
		//���Ԓn�_
		const siv::Vec2 m_stopPos;
		//�ގU�n�_
		const siv::Vec2 m_endPos;
	public:
		EnemyBase(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize )
			:FontObject(fontSize),m_startPos(startPos),m_stopPos(stopPos),m_endPos(endPos)
		{
		};
	};
}

#define ENEMYCONSTRUCTER(_NAME_) \
_NAME_::_NAME_(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)\
	:EnemyBase(startPos, stopPos,endPos,fontSize)

#define ENEMYCONSTRUCTER_DECL(_NAME_) \
_NAME_(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)
