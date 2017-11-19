#pragma once

namespace game {

	class BulletList;

	//�͂𗭂߂ĕ���l���̑�Z
	class PowerBlast {
		//�e���X�g
		std::unique_ptr<BulletList> m_bulletList;
		int count = 0;
		siv::Vec2 m_pos;
	public:
		PowerBlast();
		~PowerBlast();
		void Start(const siv::Vec2&);
		void Update();
		void Draw()const;
	};

}