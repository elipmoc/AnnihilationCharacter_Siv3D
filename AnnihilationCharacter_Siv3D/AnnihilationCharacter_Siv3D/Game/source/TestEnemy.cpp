#include "TestEnemy.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using siv::Vec2;
	ENEMYCONSTRUCTER(TestEnemy) {
		SetText(
			L"         �Q�Q�Q_�@�@\n"
			L"      �^�@�@ �@ �_\n"
			L"    �^�@���@�@ �� �_\n"
			L"  �^�@ (���j �i���j �_\n"
			L"  |     �i__�l__�j      |\n"
			L"  /        ���m ��        �^\n"
			L"  (   �_�@�^ �Q�m  | |\n"
			L"   �_ �g�@ �^  �Q�Q| |\n"
			L"      �_ �^ �Q�Q�Q �^\n"
		);

		SetPos( startPos );
		SetColor(siv::Palette::Yellow);
		//�Ă��ړ�
		AddAction(
			elipmocframework::ScaleAction::Create(1, 30)<<
			MoveAction::Create(endPos, 50) <<
			MoveAction::Create(stopPos, 180) 
			
		);
	}

	void TestEnemy::Update()
	{
		FontObject::Update();
	}
}
