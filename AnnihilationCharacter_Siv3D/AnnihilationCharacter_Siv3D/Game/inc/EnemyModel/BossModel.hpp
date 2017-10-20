#pragma once
#include "EnemyModelInfo.hpp"

namespace game {

	class BossModel:public EnemyModelInfoGenerator{
	
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const override final{

			EnemyModelInfo info;
			info.text =
				L"          �Q�Q�Q_�@�@\n"
				L"       �^�@�@ �@   �_\n"
				L"    �^�@ ���@�@ ��  �_\n"
				L" �^ �@   (���j   �i��)  �_\n"
				L" |           �i__�l__�j       |\n"
				L" /         ���m ��     �^\n"
				L"  (   �_�@�^ �Q�m  |   |\n"
				L"   �_ �g�@  �^ �Q�Q|   |\n"
				L"      �_ �^ �Q�Q�Q �^\n"
				;
			info.color = siv::Palette::Yellow;
			info.r = 50;
			return info;
		}
	};
}