#include "Boss.hpp"
#include "BulletList.hpp"
#include "FontObject.hpp"
#include "EnemyModel\BossModel.hpp"
#include "BossBehavior.hpp"


namespace game {
	Boss::Boss(Level level, const siv::Vec2 & playerRefPos, BulletListCreator& bulletListCreator):
		m_level(level),m_playerRefPos(playerRefPos),m_bulletListCreator(bulletListCreator),
		m_fontObject(std::make_unique<elipmocframework::FontObject>(12, L"‚l‚r ‚oƒSƒVƒbƒN"))
	{
		BossModel b;
		m_fontObject->SetText(b.GenerateEnemyModelInfo().text);
	}
	Boss::~Boss() = default;

	void Boss::SetBossBehavior(std::unique_ptr<BossBehavior> bossBehavior)
	{
		m_bossBehavior = std::move(bossBehavior);
	}

	void Boss::Update()
	{
		if (m_bossBehavior != nullptr) {
			m_bossBehavior->Update();
		}
	}
	void Boss::Draw() const
	{
		m_fontObject->Draw();
	}
}