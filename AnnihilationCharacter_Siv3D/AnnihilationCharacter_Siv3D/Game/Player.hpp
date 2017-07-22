#pragma once
#include "FontObject.hpp"
#include <memory>

namespace game {

	class TerrainControl;
	class Player :public elipmocframework::FontObject {

		static constexpr double speed=3.5;
		//重力加速度
		static constexpr double m_g=0.4;
		//Yの速度
		double m_yv=0;
		//ジャンプした回数記録
		int m_jumpCount=0;
		//デバック用
		siv::Circle circle;

		//自分の足元にある地形レーン
		int m_underLane = 2;

		//移動アクション
		void Move(const std::unique_ptr<TerrainControl>&);
	public:
		Player():circle(3){}

		//主人公の足元のYを得る
		double GetUnderY() {
			return GetPos().y + 35 ;
		}

		//主人公の足元のXを得る
		double GetUnderX() {
			return GetPos().x + 15;
		}

		//主人公の足元の高さをセットする
		void SetUnderY(double y) {
			SetPos({ GetPos().x,y - 35 });
		}

		void Update2(const std::unique_ptr<TerrainControl>&);
	};

}