#pragma once

namespace game {

	class BulletListCreator;

	//—Í‚ğ—­‚ß‚Ä•ú‚ÂålŒö‚Ì‘å‹Z
	class PowerBlast {
		//’eƒŠƒXƒg
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		int count = 0;
		const siv::Vec2 m_pos;
	public:
		PowerBlast(const BulletListCreator&,const siv::Vec2);
		~PowerBlast();
	};

}