#include "BarrageBase.hpp"
#include "BulletListCreator.hpp"

namespace game {

	BulletListCreator & BarrageBase::GetBulletListCreator()
	{
		return *m_bulletListCreator;
	}

	BarrageBase::BarrageBase(
		BulletListCreator& bulletListCreator,const Level level, 
		const siv::Vec2& bindPos,const siv::Vec2& playerBindPos, const siv::Vec2& fixPos)

		:m_bulletListCreator(std::make_unique<BulletListCreator>(bulletListCreator)),m_bindPos(bindPos),m_fixPos(fixPos),
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
		else if (m_level == Level::Rengoku)
			RengokuUpdate();
		else 
			YawarakaUpdate();
	}

	/*void BarrageBase::Draw()const
	{
		m_bulletListCreator.Draw();
	}*/
}