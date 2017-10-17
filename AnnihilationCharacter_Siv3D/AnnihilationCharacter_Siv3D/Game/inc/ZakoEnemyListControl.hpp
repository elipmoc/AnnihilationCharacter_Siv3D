#pragma once
#include "SceneBase.hpp"

namespace game {

	class EnemyList;
	class EnemyBuilder;
	class BulletList;
	class GameCounterReader;

	class ZakoEnemyListControl {
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		BulletList& m_bulletList;
		const GameCounterReader& m_counter;
		size_t index = 0;
		const Level m_level;
	public:
		ZakoEnemyListControl(const Level, const GameCounterReader&, BulletList&, std::unique_ptr<EnemyBuilder>);
		~ZakoEnemyListControl();
		void Update();
		void Draw()const;
	};

}