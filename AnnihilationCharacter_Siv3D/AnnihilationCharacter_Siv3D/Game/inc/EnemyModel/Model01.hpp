#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class Model01 :public EnemyModelInfoGenerator {

	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final {
			EnemyModelInfo info;
			info.text =L"!(^^)!";
			info.color = siv::Palette::Aqua;
			info.r = 0;
			return info;
		}
	};
}