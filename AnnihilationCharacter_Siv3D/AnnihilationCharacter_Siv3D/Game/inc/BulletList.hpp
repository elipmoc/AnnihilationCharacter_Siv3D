#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;

	//íeï€éùÉNÉâÉX
	class BulletList {
		using BulletPool = elipmocframework::ObjectPool<Bullet>;

		//íeÉvÅ[Éã
		std::unique_ptr<BulletPool> m_bulletPool;
	public:
		BulletList(size_t poolSize);
		void Draw()const;
		void Update();

		//íeê∂ê¨
		void MakeBullet(const siv::Vec2& pos,const siv::Vec2& speedv,const siv::Vec2& vspeedv);
		~BulletList();
	};
}