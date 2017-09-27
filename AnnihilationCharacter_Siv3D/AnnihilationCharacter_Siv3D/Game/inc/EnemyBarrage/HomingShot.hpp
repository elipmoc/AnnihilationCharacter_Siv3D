#pragma once
#include "BarrageBase.hpp"

namespace game {
	class HomingShot :public BarrageBase {
	public:
		template<class... Args>
		HomingShot(Args&&...args) :BarrageBase(30, std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}