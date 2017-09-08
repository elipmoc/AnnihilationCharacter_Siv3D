#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HorizontalShotOne :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		HorizontalShotOne(Args&&...args) :BarrageBase(1, std::forward<Args>(args)...) {}
		virtual void Update()override final;
	};
}