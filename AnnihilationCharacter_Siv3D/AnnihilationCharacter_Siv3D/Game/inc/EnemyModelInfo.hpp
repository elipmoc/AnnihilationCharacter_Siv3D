#pragma once
namespace game {

	//敵のあたり判定と見た目の情報
	struct EnemyModelInfo {
		//敵の文字列
		siv::String text;
		//敵のカラー
		siv::Color color;
		//あたり判定の位置を調整
		siv::Vec2 collisionOffsetPos = {0,0};
		//あたり判定の半径
		double r=0;
	};

	//EnemyModelInfoを生成するビルダークラス用のinterface
	class EnemyModelInfoGenerator {
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const = 0;
	};

}