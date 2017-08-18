#include "EnemyBase.hpp"
#include "BarrageBase.hpp"
#include "EnemyActionBase.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;

	Enemy::Enemy(
		std::unique_ptr<BarrageBase> &&barrage,
		std::unique_ptr<EnemyActionBase> && action,
		std::unique_ptr<FontObject> && enemyFont
		)
		:
		m_barrage(std::move(barrage)),
		m_action(std::move(action)),
		m_enemyFont(std::move(enemyFont))
	{}

	void Enemy::Update() {
		m_barrage->Update();
		m_action->Update();
		m_enemyFont->Update();
	}

	void Enemy::Draw() const
	{
		m_barrage->Draw();
		m_enemyFont->Draw();
	}

	Enemy::~Enemy()
	{
	}
}
