#include "BossBehavior.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossBehavior::BossBehavior(const Level level,const siv::Vec2& playerRefPos ,const BulletListCreator & bulletListCreator):
		m_level(level),
		m_playerRefPos(playerRefPos),
		m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator))

	{
	}
	void BossBehavior::Update()
	{
		if (m_level == Level::Normal)
			NormalUpdate();
		else if (m_level == Level::Rengoku)
			RengokuUpdate();
		else
			YawarakaUpdate();
	}
}