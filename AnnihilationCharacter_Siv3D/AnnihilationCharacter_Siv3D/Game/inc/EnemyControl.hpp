#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BasePhase;
	class BulletList;
	class GameCounterReader;

	class EnemyControl {
		const Level m_level;
		std::unique_ptr<BulletList> m_bulletList;
		const GameCounterReader& m_count;
		std::unique_ptr<BasePhase> m_phase;
		const siv::Vec2& m_playerRefPos;
		
		
		int index = 0;

	public:
		/*
		param:
			難易度,主人公のRef座標,スタートするタイミング
		*/
		EnemyControl(const Level level,const siv::Vec2&,const GameCounterReader&);
		~EnemyControl();
		//ボスフェーズに切り替え
		void SwitchBossPhase();
		void Draw()const;
		void Update();
	};
}