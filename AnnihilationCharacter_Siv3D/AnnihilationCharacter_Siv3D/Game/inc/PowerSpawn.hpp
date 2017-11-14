#pragma once
#include <vector>

namespace game {

	class Power;
	//フィールドに力を生成するクラス
	class PowerSpawn {
		std::vector<std::unique_ptr<Power>> m_powerList;
		//カウント用
		size_t count = 0;
	public:

		PowerSpawn();
		~PowerSpawn();

		//力描画
		void Draw()const;
		//力更新
		void Update();
	};
}