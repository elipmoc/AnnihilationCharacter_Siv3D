#include "EnemyControl.hpp"
#include "EnemyList.hpp"

namespace game {

	EnemyControl::EnemyControl():m_enemyList(std::make_unique<EnemyList>())
	{
	}
	EnemyControl::~EnemyControl() = default;
	void EnemyControl::Draw() const
	{
	}
	void EnemyControl::Update()
	{
	}
}
