#include "Barrage.hpp"
#include "Bullet.hpp"
#include "ObjectPool.hpp"
namespace game {

	Barrage::Barrage(size_t poolSize)
		:m_bulletPool(std::make_unique<BulletPool>(poolSize))
	{
	}

	void Barrage::Draw()const
	{
		for (const auto& item : *m_bulletPool)
			item.Draw();
	}

	void Barrage::Update()
	{
		for (auto&& item : *m_bulletPool)
			item.Update();
	}

	void Barrage::MakeBullet(const siv::Vec2 & pos, const siv::Vec2 & speedv, const siv::Vec2 & vspeedv)
	{
		m_bulletPool->New(pos,speedv,vspeedv);
	}


	Barrage::~Barrage()
	{
	}
}
