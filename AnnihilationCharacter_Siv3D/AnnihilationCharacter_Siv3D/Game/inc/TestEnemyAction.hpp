#pragma once
#include "EnemyActionBase.hpp"

namespace game {
	class TestEnemyAction :public EnemyActionBase {
	public:

		virtual std::unique_ptr<elipmocframework::ActionBase> GenerateEnemyAction(
			const siv::Vec2&,
			const siv::Vec2&,
			const siv::Vec2&
		) const override final;
	};
}