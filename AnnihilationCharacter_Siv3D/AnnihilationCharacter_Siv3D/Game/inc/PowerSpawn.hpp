#pragma once
#include <vector>

namespace game {

	class Power;
	//フィールドに力を生成するクラス
	class PowerSpawn {
	
		std::unique_ptr<std::vector<Power>> m_powerList;
	public:

		PowerSpawn();
		~PowerSpawn();

		//力描画
		void Draw()const;
		//力更新
		void Update();
	};
}