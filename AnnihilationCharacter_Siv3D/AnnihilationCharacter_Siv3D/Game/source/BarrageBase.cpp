#include "BarrageBase.hpp"
#include "BulletList.hpp"

namespace game {

	BulletList & BarrageBase::GetBulletList()
	{
		return *m_bulletList.get();
	}

	BarrageBase::BarrageBase(const size_t bulletSize)
		:m_bulletList(std::make_unique<BulletList>(bulletSize))
	{}


	BarrageBase::~BarrageBase()
	{
	}

	void BarrageBase::Draw()const
	{
		m_bulletList->Draw();
	}
}