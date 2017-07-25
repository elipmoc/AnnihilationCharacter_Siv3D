#pragma once
#include <vector>
#include <memory>

namespace game {
	class EnemyBase;
	class EnemyList {
		std::vector<std::unique_ptr<EnemyBase>> m_enemys;
	public:
		void push_back(std::unique_ptr<EnemyBase>&& enemy);
		EnemyList();
		~EnemyList();
		void Update();
		void Draw()const;
	};
}