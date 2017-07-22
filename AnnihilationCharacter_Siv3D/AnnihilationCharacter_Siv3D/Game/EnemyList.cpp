#include "EnemyList.hpp"
#include "EnemyBase.hpp"

namespace game {
	void EnemyList::push_back(std::unique_ptr<EnemyBase>&& enemy)
	{
		m_enemys.push_back(std::move(enemy));
	}
	EnemyList::EnemyList()
	{
	}

	EnemyList::~EnemyList() = default;

	void EnemyList::Update()
	{
		for (auto&& item : m_enemys)
			item->Update();
	}
	void EnemyList::Draw()const
	{
		for (const auto& item : m_enemys)
			item->Draw();
	}
}
