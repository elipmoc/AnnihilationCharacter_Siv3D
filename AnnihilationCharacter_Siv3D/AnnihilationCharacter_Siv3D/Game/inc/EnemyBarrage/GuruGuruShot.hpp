#pragma once
#include "BarrageBase.hpp"

namespace game {
	class GuruGuruShot :public BarrageBase {
		int count = 0;
		double angle = 0;
	public:
		template<class... Args>
		GuruGuruShot(Args&&...args) :BarrageBase(500, std::forward<Args>(args)...) {}
		virtual void NormalUpdate()override final;
		virtual void RengokuUpdate()override final;
	};
}