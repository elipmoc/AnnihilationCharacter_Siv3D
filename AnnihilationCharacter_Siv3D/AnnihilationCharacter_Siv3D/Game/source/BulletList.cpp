#include "BulletList.hpp"
#include "Bullet.hpp"
#include "ObjectPool.hpp"
namespace game {

	BulletList::BulletList(size_t poolSize)
		:m_bulletPool(std::make_unique<BulletPool>(poolSize))
	{
	}

	void BulletList::Draw()const
	{
		for (const auto& item : *m_bulletPool)
			item.DrawCenter();
	}

	void BulletList::Update()
	{

		elipmocframework::DeleteIf(
			*m_bulletPool, [](const Bullet& bullet) {
			return bullet.IsEnableDelete();
		});

		for (auto&& item : *m_bulletPool)
			item.Update();
	}

	void BulletList::MakeBullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv)
	{
		m_bulletPool->New(pos,speedv,vspeedv);
	}


	BulletList::~BulletList()
	{
	}
}
