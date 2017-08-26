#pragma once
#include <vector>
#include <memory>

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyControl {
		//std::unique_ptr<EnemyInfo> infoo;
		std::vector<std::unique_ptr<EnemyInfo>> m_enemyInfoList;
		std::unique_ptr<EnemyList> m_enemyList;
		int count=0;
		int index = 0;
	public:
		EnemyControl();
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}