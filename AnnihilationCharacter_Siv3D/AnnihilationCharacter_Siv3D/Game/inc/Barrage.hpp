#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;
	class BulletEX;
	class Barrage {
		using BulletPool = elipmocframework::ObjectPool<Bullet, BulletEX>;
		std::unique_ptr<BulletPool> m_bulletPool;
	public:
		Barrage(size_t poolSize);
		void Draw()const;
		void Update();
		void MakeBullet(const siv::Vec2& pos,const siv::Vec2& speedv,const siv::Vec2& vspeedv);
		~Barrage();
	};
}