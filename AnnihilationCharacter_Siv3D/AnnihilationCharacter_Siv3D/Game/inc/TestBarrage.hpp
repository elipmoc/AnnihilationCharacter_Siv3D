#pragma once
#include "BarrageBase.hpp"

namespace game {
	class TestBarrage :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		TestBarrage(Args&&...args):BarrageBase(100,std::forward<Args>(args)...) {}
		virtual void Update()override final;
	};
}