#include "BossBehavior.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossBehavior::BossBehavior(const BulletListCreator & bulletListCreator):
		m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator))
	{
	}
}