#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;
	struct BulletInfo;

	//弾保持クラス
	class BulletList {
		using BulletPool = elipmocframework::ObjectPool<Bullet>;

		//弾プール
		std::unique_ptr<BulletPool> m_bulletPool;
	public:
		BulletList(size_t poolSize);
		void Draw()const;
		void Update();

		//弾生成
		void MakeBullet(const BulletInfo&);
		~BulletList();
	};
}