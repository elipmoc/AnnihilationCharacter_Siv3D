#include "EnemyList.hpp"
#include "Enemy.hpp"
#include "ObjectPool.hpp"

namespace game {
	void EnemyList::push_back(std::unique_ptr<Enemy>&& enemy)
	{
		m_enemys.push_back(std::move(enemy));
	}
	EnemyList::EnemyList()
	{
	}

	EnemyList::~EnemyList() = default;

	void EnemyList::Update()
	{
		auto itr=std::remove_if(
			m_enemys.begin(),m_enemys.end(),
			[](const std::unique_ptr<Enemy>& enemy) {
			return enemy->IsEnableDelete();
		});

		m_enemys.erase(itr, m_enemys.end());

		for (auto&& item : m_enemys)
			item->Update();
	}
	void EnemyList::Draw()const
	{
		for (const auto& item : m_enemys)
			item->Draw();
	}
}
