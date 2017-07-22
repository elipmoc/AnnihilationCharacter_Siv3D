#pragma once

namespace game {
	class EnemyList;
	class EnemyControl {
		std::unique_ptr<EnemyList> m_enemyList;
	public:
		EnemyControl();
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}