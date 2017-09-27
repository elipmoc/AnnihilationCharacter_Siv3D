#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyBuilder;

	class EnemyControl {
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		int count=0;
		int index = 0;
		const Level m_level;
	public:
		EnemyControl(const Level level,const siv::Vec2&);
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}