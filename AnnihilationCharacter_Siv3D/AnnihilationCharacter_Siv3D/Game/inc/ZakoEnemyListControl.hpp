#pragma once
#include "SceneBase.hpp"

namespace game {

	class EnemyList;
	class EnemyBuilder;
	class BulletListCreator;
	class GameCounterReader;

	class ZakoEnemyListControl {
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		const GameCounterReader& m_counter;
		size_t index = 0;
		const Level m_level;
	public:
		ZakoEnemyListControl(const Level, const GameCounterReader&,const BulletListCreator&, std::unique_ptr<EnemyBuilder>);
		~ZakoEnemyListControl();
		void Update();
		void Draw()const;
	};

}