#pragma once
#pragma once
namespace game {
	class BulletList;
	class BulletInfo;

	class BulletListCreator {
		BulletList& m_bulletList;
	public:
		BulletListCreator(BulletList&);
		void MakeBullet(const BulletInfo&);
		
	};

}