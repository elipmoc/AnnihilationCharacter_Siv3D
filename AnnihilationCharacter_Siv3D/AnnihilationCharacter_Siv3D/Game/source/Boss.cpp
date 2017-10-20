#include "Boss.hpp"
#include "BulletList.hpp"
#include "FontObject.hpp"
#include "EnemyModel\BossModel.hpp"


namespace game {
	Boss::Boss(Level level, const siv::Vec2 & playerRefPos, BulletList& bulletList):
		m_level(level),m_playerRefPos(playerRefPos),m_bulletList(bulletList),
		m_fontObject(std::make_unique<elipmocframework::FontObject>(12, L"�l�r �o�S�V�b�N"))
	{
		BossModel b;
		m_fontObject->SetText(b.GenerateEnemyModelInfo().text);
	}
	Boss::~Boss() = default;
	void Boss::Update()
	{
	}
	void Boss::Draw() const
	{
		m_fontObject->Draw();
	}
}