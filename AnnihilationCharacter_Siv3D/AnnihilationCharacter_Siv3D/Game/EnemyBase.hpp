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
		EnemyBase(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos )
			:FontObject(30),m_startPos(startPos),m_stopPos(stopPos),m_endPos(endPos)
		{
			SetText(L"�G");
			SetPos({ 600, 150 });
			SetColor(siv::Palette::Purple);
		};
		virtual void Update()override;
	};
}