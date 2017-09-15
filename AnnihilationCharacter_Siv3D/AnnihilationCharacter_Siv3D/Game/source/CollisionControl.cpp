#include "CollisionCircle.hpp"
#include "CollisionControl.hpp"

namespace game {
	//インスタンス実体化
	CollisionControl CollisionControl::m_instance;


	CollisionControl::~CollisionControl() = default;

	void CollisionControl::PushCollisionData(const CollisionData & colliData)
	{
		m_collisions.push_back(std::unique_ptr<const CollisionData>(&colliData));
	}

	void CollisionControl::Update()
	{
		//無効なCollisionDataを削除する
		auto tail_itr = std::remove_if(m_collisions.begin(), m_collisions.end(), [](const auto& colliData) {
			return colliData->IsEnableDelete();
		});
		m_collisions.erase(tail_itr, m_collisions.end());
		//あたり判定する
		for (size_t i = 0; i < m_collisions.size(); i++) {
			for (size_t j = i + 1; j < m_collisions.size(); j++) {
				if(m_collisions[i]->IsEnable()&& m_collisions[j]->IsEnable())
					m_collisions[i]->m_collision.HitCheck(m_collisions[j]->m_collision);
			}
		}
	}

	void CollisionControl::DebugDraw()
	{
		for (const auto& item : m_collisions) {
			if (item->IsEnableDelete() == false)
				item->m_collision.DebugDraw();
		}
	}

}