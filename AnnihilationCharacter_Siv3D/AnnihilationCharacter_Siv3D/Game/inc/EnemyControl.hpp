#pragma once
#include <vector>
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class EnemyList;
	struct EnemyInfo;
	class EnemyBuilder;
	class BulletList;

	class EnemyControl {
		std::unique_ptr<EnemyBuilder> m_enemyBuilder;
		std::unique_ptr<EnemyList> m_enemyList;
		std::unique_ptr<BulletList> m_bulletList;
		int m_count=0;
		int index = 0;
		const Level m_level;
	public:
		/*
		param:
			難易度,主人公のRef座標,スタートするタイミング
		*/
		EnemyControl(const Level level,const siv::Vec2&,const int startCount=0 );
		~EnemyControl();
		void Draw()const;
		void Update();
	};
}