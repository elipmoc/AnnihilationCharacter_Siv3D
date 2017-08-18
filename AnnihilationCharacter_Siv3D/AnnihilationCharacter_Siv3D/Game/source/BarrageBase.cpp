#include "BarrageBase.hpp"
#include "BulletList.hpp"

namespace game {

	BulletList & BarrageBase::GetBulletList()
	{
		return *m_bulletList.get();
	}

	BarrageBase::BarrageBase(const size_t bulletSize, const siv::Vec2& bindPos, const siv::Vec2& fixPos)
		:m_bulletList(std::make_unique<BulletList>(bulletSize)),m_bindPos(bindPos),m_fixPos(fixPos)
	{}

	BarrageBase::~BarrageBase()
	{
	}

	void BarrageBase::Draw()const
	{
		m_bulletList->Draw();
	}
}