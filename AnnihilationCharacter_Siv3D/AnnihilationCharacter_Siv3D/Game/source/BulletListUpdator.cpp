#include "BulletListUpdator.hpp"
#include "BulletList.hpp"

namespace game {

	BulletListUpdator::BulletListUpdator(BulletList & bulletList):
		m_bulletList(bulletList)
	{}

	void BulletListUpdator::Draw() const
	{
		m_bulletList.Draw();
	}
	void BulletListUpdator::Update()
	{
		m_bulletList.Update();
	}
}