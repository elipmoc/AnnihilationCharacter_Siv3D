#pragma once
#include "FontObject.hpp"

namespace game {
	class EnemyBase :public elipmocframework::FontObject{
	protected:
		//開始地点
		const siv::Vec2 m_startPos;
		//中間地点
		const siv::Vec2 m_stopPos;
		//退散地点
		const siv::Vec2 m_endPos;
	public:
		EnemyBase(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos )
			:FontObject(30),m_startPos(startPos),m_stopPos(stopPos),m_endPos(endPos)
		{
			SetText(L"敵");
			SetPos({ 600, 150 });
			SetColor(siv::Palette::Purple);
		};
		virtual void Update()override;
	};
}