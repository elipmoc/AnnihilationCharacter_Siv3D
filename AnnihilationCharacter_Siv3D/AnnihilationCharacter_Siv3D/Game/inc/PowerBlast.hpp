#pragma once

namespace game {

	class BulletListCreator;

	//�͂𗭂߂ĕ���l���̑�Z
	class PowerBlast {
		//�e���X�g
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		int count = 0;
		const siv::Vec2 m_pos;
	public:
		PowerBlast(const BulletListCreator&,const siv::Vec2);
		~PowerBlast();
	};

}