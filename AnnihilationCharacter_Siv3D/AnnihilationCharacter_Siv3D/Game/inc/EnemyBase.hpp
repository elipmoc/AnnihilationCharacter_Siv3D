#pragma once

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class BarrageBase;
	class EnemyActionBase;
	class Enemy{
	protected:
		//弾幕
		std::unique_ptr<BarrageBase> m_barrage;
		//移動
		std::unique_ptr<EnemyActionBase> m_action;
		
		std::unique_ptr<elipmocframework::FontObject> m_enemyFont;
	public:
		Enemy(
			std::unique_ptr<BarrageBase>&&,
			std::unique_ptr<EnemyActionBase>&&,
			std::unique_ptr<elipmocframework::FontObject>&&);
		void Draw()const;
		void Update();
		~Enemy();
	};
}

/*
//継承先のEnemyのコンストラクタ定義用
#define ENEMYCONSTRUCTER(_NAME_) \
template<class BarrageT> \
_NAME_::_NAME_(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)\
	:EnemyBase<BarrageT>(startPos, stopPos,endPos,fontSize)

//継承先のEnemyのコンストラクタ宣言用
#define ENEMYCONSTRUCTER_DECL(_NAME_) \
template<class BarrageT> \
_NAME_(const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)
*/