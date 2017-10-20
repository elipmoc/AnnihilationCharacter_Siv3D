#pragma once
namespace game {
	class BulletList;

	class BulletListUpdator {
		BulletList& m_bulletList;
	public:
		BulletListUpdator(BulletList&);
		void Draw()const;
		void Update();
	};

}