#pragma once
#include "EnemyInfo.hpp"

namespace game {
	class Enemy;
	class EnemyBuilder {
		
		class EnemyBuilderImpl;
		static EnemyBuilderImpl impl;
	public:
		static std::unique_ptr<Enemy> EnemyBuild(const EnemyInfo&);
	};
}