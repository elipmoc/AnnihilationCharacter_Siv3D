#pragma once
#include "EnemyInfo.hpp"
#include "SceneBase.hpp"

namespace game {
	class Enemy;
	class EnemyBuilder {
		
		class EnemyBuilderImpl;
		static EnemyBuilderImpl impl;
	public:
		static std::unique_ptr<Enemy> EnemyBuild(const EnemyInfo&,const Level level);
	};
}