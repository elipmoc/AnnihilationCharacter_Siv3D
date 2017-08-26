#include "Enemy.hpp"
#include "BarrageBase.hpp"
#include "EnemyActionBase.hpp"
#include "EnemyModelInfo.hpp"
#include "FontObject.hpp"
#include "CollisionCircle.hpp"
namespace game {
	using elipmocframework::FontObject;

	Enemy::Enemy(
		int lifeTime,
		const EnemyModelInfo& info,
		std::unique_ptr<BarrageBase> &&barrage,
		std::unique_ptr<FontObject> && enemyFont
	)
		:
		m_lifeTime(lifeTime),
		m_barrage(std::move(barrage)),
		m_enemyFont(std::move(enemyFont)),
		m_collision(std::make_unique<CollisionCircle>(m_enemyFont->GetRefPos(), [](auto) {}))
	{
		m_collision->SetCollisionID(CollisionID::EnemyID);
		m_collision->SetR(info.r);
		m_collision->SetOffsetPos(info.collisionOffsetPos);
		m_enemyFont->SetText(info.text);
		m_enemyFont->SetColor(info.color);
	}

	void Enemy::Update() {
		if (m_lifeTime == 0)delete_flag = true;
		m_lifeTime--;
		m_barrage->Update();
		m_enemyFont->Update();
	}

	void Enemy::Draw() const
	{
		m_barrage->Draw();
		m_enemyFont->DrawCenter();
	}

	Enemy::~Enemy()
	{
	}
}
