#include "PowerBlast.hpp"
#include"BulletList.hpp"

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
				m_bulletList->MakeBullet(m_pos, { 2,0 }, { 0.1,0 });
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