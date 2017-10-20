#include "BulletList.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BulletListCreator::BulletListCreator(BulletList& bulletList):
		m_bulletList(bulletList)
	{
	}
	void BulletListCreator::MakeBullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv)
	{
		m_bulletList.MakeBullet(pos, speedv, vspeedv);
	}
}