#include "Enemy.hpp"
#include "BarrageBase.hpp"
#include "EnemyActionBase.hpp"
#include "EnemyModelInfo.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;

	Enemy::Enemy(
		const EnemyModelInfo& info,
		std::unique_ptr<BarrageBase> &&barrage,
		std::unique_ptr<FontObject> && enemyFont
		)
		:
		m_barrage(std::move(barrage)),
		m_enemyFont(std::move(enemyFont))
		{
		m_enemyFont->SetText(info.text);
		m_enemyFont->SetColor(info.color);
	}

	void Enemy::Update() {
		m_barrage->Update();
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
