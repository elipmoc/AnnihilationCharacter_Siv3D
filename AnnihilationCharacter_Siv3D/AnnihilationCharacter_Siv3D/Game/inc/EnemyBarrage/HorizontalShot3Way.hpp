#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HorizontalShot3Way :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		HorizontalShot3Way(Args&&...args) :BarrageBase(3, std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}