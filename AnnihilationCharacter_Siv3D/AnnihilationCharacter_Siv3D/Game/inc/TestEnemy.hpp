#pragma once
#include "EnemyBase.hpp"

namespace game {
	class TestEnemy :public EnemyBase {
	public:
		ENEMYCONSTRUCTER_DECL(TestEnemy);

		virtual void Update()override;
	};
}