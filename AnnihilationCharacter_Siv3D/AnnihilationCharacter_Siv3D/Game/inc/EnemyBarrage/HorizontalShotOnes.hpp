#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HorizontalShotOnes :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		HorizontalShotOnes(Args&&...args) :BarrageBase(std::forward<Args>(args)...) {}
		virtual void YawarakaUpdate()override final;
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}