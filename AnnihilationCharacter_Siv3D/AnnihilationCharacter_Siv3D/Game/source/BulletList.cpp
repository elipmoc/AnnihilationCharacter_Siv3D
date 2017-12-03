#include "BulletList.hpp"
#include "Bullet.hpp"
#include "ObjectPool.hpp"
#include "BulletInfo.hpp"

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

	void BulletList::MakeBullet(const BulletInfo& bInfo)
	{
		auto& bullet = m_bulletPool->New(bInfo.pos, bInfo.speed, bInfo.vspeed,bInfo.colliID,bInfo.fontSize);
		bullet.SetColor(bInfo.color);
		if (bInfo.glowFlag) {
			bullet.SetGlow(bInfo.blur, bInfo.gamma);
			bullet.SetGlowColor(bInfo.glowColor);
		}
		bullet.SetcontinuationForce(bInfo.continuationForce);
		bullet.SetmomentForce(bInfo.momentForce);
		bullet.SetK(bInfo.k);
		bullet.SetFunc(bInfo.func);
	}


	BulletList::~BulletList()
	{
	}
}
