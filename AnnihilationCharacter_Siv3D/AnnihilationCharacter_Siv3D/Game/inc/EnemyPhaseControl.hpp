#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BasePhase;
	class BossPhase;
	class BulletList;
	class GameCounterReader;
	class TerrainControl;

	class EnemyPhaseControl {
		TerrainControl& m_terrainControl;
		const Level m_level;
		std::unique_ptr<BulletList> m_bulletList;
		std::unique_ptr<BasePhase> m_phase;
		std::unique_ptr<BossPhase> m_bossPhase;
		const siv::Vec2& m_playerRefPos;
		int index = 0;

	public:
		/*
		param:
			��Փx,��l����Ref���W,�X�^�[�g����^�C�~���O
		*/
		EnemyPhaseControl(const Level level,const siv::Vec2&,const GameCounterReader&,TerrainControl&);
		~EnemyPhaseControl();
		//�{�X�t�F�[�Y�ɐ؂�ւ�
		void SwitchBossPhase();
		void Draw()const;
		void Update();
		//�Q�[�����N���A���邩�̃t���O
		bool IsClear();
	};
}