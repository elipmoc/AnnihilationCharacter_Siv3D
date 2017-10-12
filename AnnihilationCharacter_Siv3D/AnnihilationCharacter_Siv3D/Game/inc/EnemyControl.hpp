#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class ZakoEnemyPhase;
	class BulletList;
	class GameCounterReader;

	class EnemyControl {
		const Level m_level;
		std::unique_ptr<BulletList> m_bulletList;
		const GameCounterReader& m_count;
		std::unique_ptr<ZakoEnemyPhase> m_zakoEnemyPhase;
		
		
		int index = 0;

	public:
		/*
		param:
			��Փx,��l����Ref���W,�X�^�[�g����^�C�~���O
		*/
		EnemyControl(const Level level,const siv::Vec2&,const GameCounterReader&);
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}