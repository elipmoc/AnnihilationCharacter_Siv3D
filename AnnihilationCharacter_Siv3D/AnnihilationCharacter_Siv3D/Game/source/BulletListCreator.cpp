#include "BulletList.hpp"
#include "BulletListCreator.hpp"
#include "BulletInfo.hpp"

namespace game {
	BulletListCreator::BulletListCreator(BulletList& bulletList):
		m_bulletList(bulletList)
	{
	}
	void BulletListCreator::MakeBullet(const BulletInfo& bInfo)
	{
		m_bulletList.MakeBullet(bInfo);
	}
}