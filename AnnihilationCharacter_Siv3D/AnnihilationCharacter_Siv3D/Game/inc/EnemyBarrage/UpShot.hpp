#pragma once
#pragma once
#include "BarrageBase.hpp"

namespace game {
	class UpShot :public BarrageBase {
		int count = 0;
	public:
		template<class... Args>
		UpShot(Args&&...args) :BarrageBase(30, std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}