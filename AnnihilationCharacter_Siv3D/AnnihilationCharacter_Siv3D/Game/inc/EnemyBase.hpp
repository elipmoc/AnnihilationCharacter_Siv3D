#pragma once
#include "FontObject.hpp"

namespace game {
	class BulletList;
	class EnemyBase :public elipmocframework::FontObject{
	protected:
		//開始地点
		const siv::Vec2 m_startPos;
		//中間地点
		const siv::Vec2 m_stopPos;
		//退散地点
		const siv::Vec2 m_endPos;
		//弾幕リスト
		std::unique_ptr<BulletList> m_barrage;
	public:
		EnemyBase(const size_t barrageSize,const siv::Vec2& startPos, const 
			
			
			siv::Vec2& stopPos, const siv::Vec2& endPos, const int fontSize);

		~EnemyBase();
	};
}


//継承先のEnemyのコンストラクタ定義用
#define ENEMYCONSTRUCTER(_NAME_) \
_NAME_::_NAME_(const size_t barrageSize,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)\
	:EnemyBase(barrageSize,startPos, stopPos,endPos,fontSize)

//継承先のEnemyのコンストラクタ宣言用
#define ENEMYCONSTRUCTER_DECL(_NAME_) \
_NAME_(const size_t barrageSize,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)
