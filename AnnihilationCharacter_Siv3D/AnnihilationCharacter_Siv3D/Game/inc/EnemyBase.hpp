#pragma once
#include "FontObject.hpp"

namespace game {
	class BarrageBase;
	class EnemyBase :public elipmocframework::FontObject{
	protected:
		//�J�n�n�_
		const siv::Vec2 m_startPos;
		//���Ԓn�_
		const siv::Vec2 m_stopPos;
		//�ގU�n�_
		const siv::Vec2 m_endPos;
		//�e��
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


//�p�����Enemy�̃R���X�g���N�^��`�p
#define ENEMYCONSTRUCTER(_NAME_) \
_NAME_::_NAME_(std::unique_ptr<BarrageBase>&& barrage,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)\
	:EnemyBase(std::move(barrage),startPos, stopPos,endPos,fontSize)

//�p�����Enemy�̃R���X�g���N�^�錾�p
#define ENEMYCONSTRUCTER_DECL(_NAME_) \
_NAME_(std::unique_ptr<BarrageBase>&& barrage,const siv::Vec2& startPos, const siv::Vec2& stopPos,const siv::Vec2& endPos,const int fontSize)
