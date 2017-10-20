#pragma once
#pragma once
namespace game {
	class BulletList;

	class BulletListCreator {
		BulletList& m_bulletList;
	public:
		BulletListCreator(BulletList&);
		void MakeBullet(
			const siv::Vec2& pos, const siv::Vec2& speedv, const siv::Vec2& vspeedv
		);
		
	};

}