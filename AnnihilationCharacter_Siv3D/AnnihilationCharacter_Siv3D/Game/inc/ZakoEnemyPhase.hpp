#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"
namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyBuilder;
	class BulletList;
	class GameCounterReader;

	class ZakoEnemyPhase {
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		BulletList& m_bulletList;
		const GameCounterReader& m_count;

		int index = 0;
		const Level m_level;
	public:
		/*
		param:
		��Փx,��l����Ref���W,�X�^�[�g����^�C�~���O
		*/
		ZakoEnemyPhase(const Level level, const siv::Vec2&, const GameCounterReader&,BulletList&);
		~ZakoEnemyPhase();
		void Draw()const;
		void Update();
	};
}