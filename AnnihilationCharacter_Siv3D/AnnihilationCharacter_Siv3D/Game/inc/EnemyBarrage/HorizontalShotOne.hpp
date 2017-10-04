#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HorizontalShotOne :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		HorizontalShotOne(Args&&...args) :BarrageBase(std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}