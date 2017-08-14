#pragma once
#include "BarrageBase.hpp"

namespace game {
	class TestBarrage :public BarrageBase {
	public:
		TestBarrage():BarrageBase(100) {}
		virtual void Update()override final;
	};
}