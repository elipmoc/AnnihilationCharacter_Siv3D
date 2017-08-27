#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <memory>

namespace game {
	struct EnemyInfo;

	//ファイルから敵生成データを読み込むクラス
	class LoadFileEnemyInfo {
		std::vector<std::unique_ptr<EnemyInfo>> m_enemyInfoList;
	public:
		LoadFileEnemyInfo();
		~LoadFileEnemyInfo();
		void LoadFile();

		const std::vector<std::unique_ptr<EnemyInfo>>& GetEnemyInfoList() {
			return m_enemyInfoList;
		}
	};
}