#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class Model03 :public EnemyModelInfoGenerator {

	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final {
			EnemyModelInfo info;
			info.text = L"<(^^)>";
			info.color = siv::Palette::Royalblue;
			info.r = 0;
			return info;
		}
	};
}