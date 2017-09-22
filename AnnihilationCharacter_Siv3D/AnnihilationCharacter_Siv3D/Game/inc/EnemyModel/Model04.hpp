#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class Model04 :public EnemyModelInfoGenerator {

	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final {
			EnemyModelInfo info;
			info.text =
				L"  ƒ© ƒ©  \n"
				L"( ^)o(^ )";
			info.color = siv::Palette::Red;
			info.r = 0;
			return info;
		}
	};
}