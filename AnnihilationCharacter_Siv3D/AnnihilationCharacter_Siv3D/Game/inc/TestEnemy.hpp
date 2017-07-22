#pragma once
#include "EnemyBase.hpp"

namespace game {
	class TestEnemy :public EnemyBase {
	public:
		ENEMYCONSTRUCTER(TestEnemy)
		{
			SetText(L"“G");
			SetPos({ 600, 150 });
			SetColor(siv::Palette::Purple);
		}
	};
}