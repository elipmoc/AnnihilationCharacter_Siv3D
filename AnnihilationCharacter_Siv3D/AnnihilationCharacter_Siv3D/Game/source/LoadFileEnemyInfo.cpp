#include "LoadFileEnemyInfo.hpp"
#include "EnemyInfo.hpp"
#include <cctype>

namespace game {




	LoadFileEnemyInfo::LoadFileEnemyInfo()
	{
	}
	LoadFileEnemyInfo::~LoadFileEnemyInfo()
	{
	}
	void LoadFileEnemyInfo::LoadFile()
	{
		try {
			const siv::JSONReader json(L"enemy.json");
			const auto enemyArray = json[L"EnemyList"].getArray();
			for (auto& enemy : enemyArray) {
				auto info_ptr = std::make_unique<EnemyInfo>();
				info_ptr->action = enemy[L"Action"].getString().narrow();
				info_ptr->startPos.x = enemy[L"StartPos"][L"x"].getNumber();
				info_ptr->startPos.y = enemy[L"StartPos"][L"y"].getNumber();
				info_ptr->stopPos.x = enemy[L"StopPos"][L"x"].getNumber();
				info_ptr->stopPos.y = enemy[L"StopPos"][L"y"].getNumber();
				info_ptr->endPos.x = enemy[L"EndPos"][L"x"].getNumber();
				info_ptr->endPos.y = enemy[L"EndPos"][L"y"].getNumber();
				info_ptr->waitTime = enemy[L"WaitTime"].getNumber();
				info_ptr->bornTime = enemy[L"BornTime"].getNumber();
				info_ptr->lifeTime = enemy[L"LifeTime"].getNumber();
				info_ptr->barrage = enemy[L"Barrage"].getString().narrow();
				info_ptr->barrageStartTime = enemy[L"BarrageStartTime"].getNumber();
				info_ptr->model = enemy[L"Model"].getString().narrow();
				m_enemyInfoList.push_back(std::move(info_ptr));
			}
		}
		catch (...) {
			throw siv::String(L"enemy.jsonÇ≈ÉGÉâÅ[Ç™î≠ê∂ÇµÇ‹ÇµÇΩ");
		}
	}

	
}