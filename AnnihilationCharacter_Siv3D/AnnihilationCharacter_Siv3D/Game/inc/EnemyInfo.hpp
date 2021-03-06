#pragma once

namespace game {

	//敵を作成するために必要な情報
	struct EnemyInfo {
		std::string action;
		siv::Vec2 startPos;
		siv::Vec2 stopPos;
		siv::Vec2 endPos;
		int waitTime;
		int lifeTime;
		int bornTime;
		std::string barrage;
		int barrageStartTime;
		std::string model;
	};

}