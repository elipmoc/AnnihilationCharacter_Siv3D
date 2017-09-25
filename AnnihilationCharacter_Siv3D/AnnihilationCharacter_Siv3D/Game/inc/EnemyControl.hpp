#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyControl {
		//std::vector<std::unique_ptr<EnemyInfo>> m_enemyInfoList;
		std::unique_ptr<EnemyList> m_enemyList;
		int count=0;
		int index = 0;
		const Level m_level;
	public:
		EnemyControl(const Level level);
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}