#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class Model05 :public EnemyModelInfoGenerator {

	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final {
			EnemyModelInfo info;
			info.text = L"(#´Д｀#)";
			info.color = siv::Palette::Lightpink;
			info.r = 0;
			return info;
		}
	};
}