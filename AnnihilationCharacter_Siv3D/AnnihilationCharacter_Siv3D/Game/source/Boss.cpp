#include "Boss.hpp"
#include "BulletList.hpp"
#include "FontObject.hpp"
#include "EnemyModel\BossModel.hpp"
#include "BossBehavior.hpp"
#include "BulletListCreator.hpp"
#include "BossBehavior01.hpp"


namespace game {
	Boss::Boss(Level level, const siv::Vec2 & playerRefPos, BulletListCreator& bulletListCreator):
		m_level(level),m_playerRefPos(playerRefPos),m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator)),
		m_fontObject(std::make_unique<elipmocframework::FontObject>(12, L"‚l‚r ‚oƒSƒVƒbƒN"))
	{
		BossModel b;
		m_fontObject->SetText(b.GenerateEnemyModelInfo().text);
		m_fontObject->SetPos({ 500, 80 });
	}
	Boss::~Boss() = default;

	void Boss::SetBossBehavior()
	{
		m_bossBehavior =std::make_unique<BossBehavior01>(*m_bulletListCreator);
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