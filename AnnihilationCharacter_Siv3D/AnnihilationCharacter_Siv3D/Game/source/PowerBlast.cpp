#include "PowerBlast.hpp"
#include"BulletList.hpp"
#include "BulletInfo.hpp"
#include "Bullet.hpp"
#include "Boss.hpp"

namespace game {
	PowerBlast::PowerBlast(const siv::Vec2& playerPosRef)
		:m_bulletList(std::make_unique<BulletList>(30)),
		m_playerPosRef(playerPosRef)
	{
	}

	PowerBlast::~PowerBlast() = default;

	void PowerBlast::Start()
	{
		m_startFlag = true;
		count = 0;
	}

	void PowerBlast::Update()
	{
		namespace math=siv::Math;
		if (m_startFlag) {
				BulletInfo bInfo;
				bInfo.fontSize = 30;
				bInfo.color = siv::Palette::Orangered;
				bInfo.colliID = CollisionID::PowerBlastID;
				bInfo.blur = 10;
				bInfo.glowFlag = true;
				bInfo.glowColor = siv::Palette::Yellow;
				bInfo.func = [](Bullet& bullet) {
					if (bullet.GetCounter() == 50) {
						siv::Vec2 addPos = 
							(Boss::BOSS_POS - bullet.GetPos()) / bullet.GetPos().distanceFrom(Boss::BOSS_POS);
						bullet.SetSpeed({ 0,0 });
						bullet.SetVspeed(addPos/5);
						
					}
				};

				constexpr int interval=10;

				if (count < interval * 18) {
					if (count % interval == 0) {
						bInfo.pos = m_playerPosRef;
						double angle = 20 * count / interval / 180.0*math::Pi;
						bInfo.speed = { math::Cos(angle) * 3,math::Sin(angle) * 3 };
						m_bulletList->MakeBullet(bInfo);
					}
				}
				else {
					m_startFlag = false;
					count = 0;
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
