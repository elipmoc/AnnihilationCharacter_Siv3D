#include "PowerBlast.hpp"
#include"BulletList.hpp"
#include "BulletInfo.hpp"
#include "Bullet.hpp"

namespace game {
	PowerBlast::PowerBlast()
		:m_bulletList(std::make_unique<BulletList>(600))
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
		namespace math=siv::Math;
		if (m_startFlag) {
				BulletInfo bInfo;
				bInfo.pos = m_pos;
				bInfo.color = siv::Palette::Orangered;
				bInfo.colliID = CollisionID::PowerBlastID;
				bInfo.blur = 10;
				bInfo.glowFlag = true;
				bInfo.glowColor = siv::Palette::Yellow;
				//bInfo.func = [](Bullet& bullet) {};
				for (size_t i = 0; i < 18; i++) {
					double angle = 20 * i / 180.0*math::Pi;
					bInfo.speed = { math::Cos(angle)*3,math::Sin(angle)*3 };
					m_bulletList->MakeBullet(bInfo);
				}
				m_startFlag = false;
			count++;
		}
		m_bulletList->Update();
	}

	void PowerBlast::Draw() const
	{
		m_bulletList->Draw();
	}
}
