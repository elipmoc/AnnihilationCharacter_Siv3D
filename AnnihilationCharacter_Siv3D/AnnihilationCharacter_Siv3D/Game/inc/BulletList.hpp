#pragma once
#include <memory>

namespace elipmocframework {
	template<class SuperT,class... SubsT>
	class ObjectPool;
}



namespace game {
	class Bullet;

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
		void MakeBullet(const siv::Vec2& pos,const siv::Vec2& speedv,const siv::Vec2& vspeedv);
		~BulletList();
	};
}