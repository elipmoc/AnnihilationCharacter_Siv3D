#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class TestEnemyModel:public EnemyModelInfoGenerator{
	
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final{

			EnemyModelInfo info;
			info.text =
				L"         ÅQÅQÅQ_Å@Å@\n"
				L"      Å^Å@Å@ Å@ Å_\n"
				L"    Å^Å@ÑüÅ@Å@ Ñü Å_\n"
				L"  Å^Å@ (ÅúÅj ÅiÅúÅj Å_\n"
				L"  |     Åi__êl__Åj      |\n"
				L"  /        ÅøÉm ÅΩ        Å^\n"
				L"  (   Å_Å@Å^ ÅQÉm  | |\n"
				L"   Å_ ÅgÅ@ Å^  ÅQÅQ| |\n"
				L"      Å_ Å^ ÅQÅQÅQ Å^\n"
				;
			info.color = siv::Palette::Yellow;
			return info;
		}
	};
}