#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BasePhase;
	class BulletList;
	class GameCounterReader;
	class TerrainControl;

	class EnemyControl {
		TerrainControl& m_terrainControl;
		const Level m_level;
		std::unique_ptr<BulletList> m_bulletList;
		const GameCounterReader& m_count;
		std::unique_ptr<BasePhase> m_phase;
		const siv::Vec2& m_playerRefPos;
		
		
		int index = 0;

	public:
		/*
		param:
			��Փx,��l����Ref���W,�X�^�[�g����^�C�~���O
		*/
		EnemyControl(const Level level,const siv::Vec2&,const GameCounterReader&,TerrainControl&);
		~EnemyControl();
		//�{�X�t�F�[�Y�ɐ؂�ւ�
		void SwitchBossPhase();
		void Draw()const;
		void Update();
	};
}