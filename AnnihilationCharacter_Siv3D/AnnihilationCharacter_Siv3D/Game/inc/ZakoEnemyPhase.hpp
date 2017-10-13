#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"
#include "BasePhase.hpp"

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyBuilder;
	class BulletList;
	class GameCounterReader;

	class ZakoEnemyPhase :public BasePhase{
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		BulletList& m_bulletList;
		const GameCounterReader& m_count;

		size_t index = 0;
		const Level m_level;
	public:
		/*
		param:
		難易度,主人公のRef座標,スタートするタイミング
		*/
		ZakoEnemyPhase(const Level level, const siv::Vec2&, const GameCounterReader&,BulletList&);
		~ZakoEnemyPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;
	};
}