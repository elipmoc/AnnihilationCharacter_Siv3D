#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HomingShot :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		HomingShot(Args&&...args) :BarrageBase(10, std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}