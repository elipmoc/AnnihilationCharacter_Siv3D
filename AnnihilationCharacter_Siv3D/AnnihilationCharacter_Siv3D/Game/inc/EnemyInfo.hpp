#pragma once

//“G‚ğì¬‚·‚é‚½‚ß‚É•K—v‚Èî•ñ
struct EnemyInfo{
	std::string action;	
	siv::Vec2 startPos;
	siv::Vec2 stopPos;
	siv::Vec2 endPos;
	int waitTime;
	int bornTime;
	std::string barrage;
	int barrageStartTime;
	std::string model;
	int hp;
};