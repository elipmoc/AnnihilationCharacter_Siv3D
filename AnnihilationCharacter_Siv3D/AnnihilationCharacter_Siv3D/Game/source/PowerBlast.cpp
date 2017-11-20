#include "PowerBlast.hpp"
#include"BulletList.hpp"
#include "BulletInfo.hpp"

namespace game {
	PowerBlast::PowerBlast()
		:m_bulletList(std::make_unique<BulletList>(30))
	{
	}

	PowerBlast::~PowerBlast() = default;

	void PowerBlast::Start(const siv::Vec2& pos)
	{
		m_startFlag = true;
		count = 0;
		m_pos = pos;
	}

	void PowerBlast::Update()
	{
		if (m_startFlag) {
			if (count % 30 == 0) {
				BulletInfo bInfo{ m_pos,{ 2,0 },{ 0.1,0 } };
				bInfo.color = siv::Palette::Orangered;
				bInfo.blur = 10;
				bInfo.glowFlag = true;
				m_bulletList->MakeBullet(bInfo);
			}
			count++;
		}
		m_bulletList->Update();
	}

	void PowerBlast::Draw() const
	{
		m_bulletList->Draw();
	}
}