#pragma once
#include <vector>
#include <memory>

namespace game {
	class Enemy;
	class EnemyList {
		std::vector<std::unique_ptr<Enemy>> m_enemys;
	public:
		void push_back(std::unique_ptr<Enemy>&& enemy);
		EnemyList();
		~EnemyList();
		void Update();
		void Draw()const;
	};
}