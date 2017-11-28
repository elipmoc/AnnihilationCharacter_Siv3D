#include "Boss.hpp"
#include "BulletList.hpp"
#include "FontObject.hpp"
#include "EnemyModel\BossModel.hpp"
#include "BossBehavior.hpp"
#include "BulletListCreator.hpp"
#include "BossBehavior01.hpp"
#include "CollisionCircle.hpp"
#include "BossBehaviorMake.hpp"

namespace game {
	Boss::Boss(Level level, const siv::Vec2 & playerRefPos, BulletListCreator& bulletListCreator):
		m_level(level),m_playerRefPos(playerRefPos),m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator)),
		m_fontObject(std::make_unique<elipmocframework::FontObject>(12, L"‚l‚r ‚oƒSƒVƒbƒN")),
		m_collision(std::make_unique<CollisionCircle>(m_fontObject->GetRefPos(),
			[this](CollisionID id) {
		if (id == CollisionID::PowerBlastID)
			this->m_hp--;
	}))
	{
		m_collision->SetR(80);
		m_collision->SetCollisionID(CollisionID::EnemyID);
		BossModel b;
		m_fontObject->SetText(b.GenerateEnemyModelInfo().text);
		m_fontObject->SetPos(BOSS_POS);
	}
	Boss::~Boss() = default;

	void Boss::SetBossBehavior(BossBehaviorMakeBase& bossBehaviorMakeBase)
	{
		m_bossBehavior= bossBehaviorMakeBase.Create(*m_bulletListCreator);
		//m_bossBehavior =std::make_unique<BossBehavior01>(*m_bulletListCreator);
	}

	void Boss::Update()
	{
		m_collision->DoColliQueue();
		if (m_bossBehavior != nullptr) {
			m_bossBehavior->Update();
		}
	}
	void Boss::Draw() const
	{
		m_fontObject->DrawCenter();
	}
}