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
		int barrageStartTime,
		const EnemyModelInfo& info,
		std::unique_ptr<BarrageBase> &&barrage,
		std::unique_ptr<FontObject> && enemyFont
	)
		:
		m_lifeTime(lifeTime),
		m_barrageStartTime(barrageStartTime),
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
		if (m_barrageStartTime == 0)
			m_barrage->Update();
		else
			m_barrageStartTime--;
		m_enemyFont->Update();
	}

	void Enemy::Draw() const
	{
		//m_barrage->Draw();
		m_enemyFont->DrawCenter();
	}

	Enemy::~Enemy()
	{
	}
}
