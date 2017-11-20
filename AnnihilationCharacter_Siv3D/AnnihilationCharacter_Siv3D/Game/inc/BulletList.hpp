#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;
	struct BulletInfo;

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
		void MakeBullet(const BulletInfo&);
		~BulletList();
	};
}