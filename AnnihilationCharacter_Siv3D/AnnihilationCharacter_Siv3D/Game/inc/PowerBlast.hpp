#pragma once

namespace game {

	class BulletList;

	//�͂𗭂߂ĕ���l���̑�Z
	class PowerBlast {
		//�e���X�g
		std::unique_ptr<BulletList> m_bulletList;
		int count = 0;
		//��l�����W�̎Q��
		const siv::Vec2& m_playerPosRef;
		bool m_startFlag=false;
	public:
		PowerBlast(const siv::Vec2& playerPosRef);
		~PowerBlast();
		void Start();
		void Update();
		void Draw()const;
	};

}