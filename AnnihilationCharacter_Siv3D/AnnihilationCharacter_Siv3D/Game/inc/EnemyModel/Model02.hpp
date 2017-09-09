#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class Model02 :public EnemyModelInfoGenerator {

	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final {
			EnemyModelInfo info;
			info.text = L"w(^^)w";
			info.color = siv::Palette::Yellow;
			info.r = 0;
			return info;
		}
	};
}