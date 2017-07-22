#pragma once
#include "FontObject.hpp"

namespace game {
	class EnemyBase :public elipmocframework::FontObject{
	public:
		EnemyBase() {};
		virtual void Update()override;
	};
}