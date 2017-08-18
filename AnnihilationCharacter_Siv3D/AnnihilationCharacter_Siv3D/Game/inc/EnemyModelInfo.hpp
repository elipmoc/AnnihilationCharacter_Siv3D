#pragma once
namespace game {

	//敵のあたり判定と見た目の情報
	struct EnemyModelInfo {
		//敵の文字列
		siv::String text;
		//あたり判定の位置を調整
		siv::Vec2 collisionOffsetPos;
		//あたり判定の半径
		double r;
	};
}