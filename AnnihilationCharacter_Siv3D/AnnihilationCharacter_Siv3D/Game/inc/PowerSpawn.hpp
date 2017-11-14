#pragma once

namespace game {

	//フィールドに力を生成するクラス
	class PowerSpawn {
		
	public:
		//力描画
		void Draw()const;
		//力更新
		void Update();
	};
}