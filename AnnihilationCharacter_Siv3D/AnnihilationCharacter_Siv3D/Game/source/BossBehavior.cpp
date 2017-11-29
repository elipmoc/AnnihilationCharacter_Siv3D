#include "BossBehavior.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossBehavior::BossBehavior(const Level level ,const BulletListCreator & bulletListCreator):
		m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator)),
		m_level(level)
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