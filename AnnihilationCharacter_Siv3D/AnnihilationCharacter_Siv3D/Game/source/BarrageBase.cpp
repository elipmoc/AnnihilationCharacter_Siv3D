#include "BarrageBase.hpp"
#include "BulletList.hpp"

namespace game {

	BulletList & BarrageBase::GetBulletList()
	{
		return m_bulletList;
	}

	BarrageBase::BarrageBase(BulletList& bulletList,const Level level, const siv::Vec2& bindPos,const siv::Vec2& playerBindPos, const siv::Vec2& fixPos)
		:m_bulletList(bulletList),m_bindPos(bindPos),m_fixPos(fixPos),
		m_level(level),
		m_playerBindPos(playerBindPos)
	{}

	BarrageBase::~BarrageBase()
	{
	}

	void BarrageBase::Update()
	{
		if (m_level == Level::Normal)
			NormalUpdate();
		else
			RengokuUpdate();
	}

	void BarrageBase::Draw()const
	{
		m_bulletList.Draw();
	}
}