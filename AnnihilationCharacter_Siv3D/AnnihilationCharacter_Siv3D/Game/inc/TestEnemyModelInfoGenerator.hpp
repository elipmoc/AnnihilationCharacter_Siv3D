#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class TestEnemyModelInfoGenerator:public EnemyModelInfoGenerator{
	
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final{

			EnemyModelInfo info;
			info.text =
				L"         �Q�Q�Q_�@�@\n"
				L"      �^�@�@ �@ �_\n"
				L"    �^�@���@�@ �� �_\n"
				L"  �^�@ (���j �i���j �_\n"
				L"  |     �i__�l__�j      |\n"
				L"  /        ���m ��        �^\n"
				L"  (   �_�@�^ �Q�m  | |\n"
				L"   �_ �g�@ �^  �Q�Q| |\n"
				L"      �_ �^ �Q�Q�Q �^\n"
				;
			info.color = siv::Palette::Yellow;
			return info;
		}
	};
}