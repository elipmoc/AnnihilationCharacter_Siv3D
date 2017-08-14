#pragma once
#include "FontObject.hpp"

namespace game {
	class BarrageBase;
	class EnemyBase :public elipmocframework::FontObject{
	protected:
		//開始地点
		const siv::Vec2 m_startPos;
		//中間地点
		const siv::Vec2 m_stopPos;
		//退散地点
		const siv::Vec2 m_endPos;
		//弾幕
		std::unique_ptr<BarrageBase> m_barrage;

	public:
		EnemyBase(
			std::unique_ptr<BarrageBase>&& barrage,
			const siv::Vec2& startPos, 
			const siv::Vec2& stopPos,
			const siv::Vec2& endPos, 
			const int fontSize);
		virtual void Draw()const;
		~EnemyBase();
	};
}


//継承先のEnemyのコンストラクタ定義用
#define ENEMYCONSTRUCTER(_NAME_) \
_NAME_::_NAME_(std::unique_ptr<BarrageBase>&& barrage,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)\
	:EnemyBase(std::move(barrage),startPos, stopPos,endPos,fontSize)

//継承先のEnemyのコンストラクタ宣言用
#define ENEMYCONSTRUCTER_DECL(_NAME_) \
_NAME_(std::unique_ptr<BarrageBase>&& barrage,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)
