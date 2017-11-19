#pragma once

namespace game {

	class BulletList;

	//—Í‚ğ—­‚ß‚Ä•ú‚ÂålŒö‚Ì‘å‹Z
	class PowerBlast {
		//’eƒŠƒXƒg
		std::unique_ptr<BulletList> m_bulletList;
		int count = 0;
		siv::Vec2 m_pos;
		bool m_startFlag=false;
	public:
		PowerBlast();
		~PowerBlast();
		void Start(const siv::Vec2&);
		void Update();
		void Draw()const;
	};

}