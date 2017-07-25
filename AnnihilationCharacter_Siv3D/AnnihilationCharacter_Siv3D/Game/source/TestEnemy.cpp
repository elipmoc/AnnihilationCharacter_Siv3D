#include "TestEnemy.hpp"
#include "Action.hpp"
#include "Actions.hpp"

namespace game {
	using  elipmocframework::MoveAction;
	using siv::Vec2;
	ENEMYCONSTRUCTER(TestEnemy) {
		SetText(L"!(^^)!");
		SetPos({ 600, 150 });
		SetColor(siv::Palette::Yellow);
		//‚Ä‚«ˆÚ“®
		AddAction(MoveAction::Create({ 400,400 }, 50) <<MoveAction::Create({ -100, GetPos().y + 130 }, 180));
	}

	void TestEnemy::Update()
	{
		FontObject::Update();
	}
}
