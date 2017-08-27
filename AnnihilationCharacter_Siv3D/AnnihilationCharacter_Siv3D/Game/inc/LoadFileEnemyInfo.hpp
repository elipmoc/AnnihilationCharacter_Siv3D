#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <memory>

namespace game {
	struct EnemyInfo;

	//�t�@�C������G�����f�[�^��ǂݍ��ރN���X
	class LoadFileEnemyInfo {
		std::vector<std::unique_ptr<EnemyInfo>> m_enemyInfoList;
	public:
		LoadFileEnemyInfo();
		~LoadFileEnemyInfo();
		void LoadFile();

		const std::vector<std::unique_ptr<EnemyInfo>>& GetEnemyInfoList()const noexcept {
			return m_enemyInfoList;
		}
	};
}