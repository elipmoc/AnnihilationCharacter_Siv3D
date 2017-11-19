#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;
	class BulletInfo;

	//�e�ێ��N���X
	class BulletList {
		using BulletPool = elipmocframework::ObjectPool<Bullet>;

		//�e�v�[��
		std::unique_ptr<BulletPool> m_bulletPool;
	public:
		BulletList(size_t poolSize);
		void Draw()const;
		void Update();

		//�e����
		void MakeBullet(const BulletInfo&);
		~BulletList();
	};
}