#pragma once
#include "CollisionCircle.hpp"
#include <memory>
namespace game {

	struct CollisionData;
	//あたり判定管理クラス（スレッドセーフなシングルトン）
	class CollisionControl {
		CollisionControl()=default;
		static CollisionControl m_instance;
		CollisionControl(const CollisionControl&) = delete;
		CollisionControl(CollisionControl&&) = delete;

		//あたり判定のリスト
		siv::Array<std::unique_ptr<const CollisionData>> m_collisions;
	public:
		static CollisionControl& GetInstance() { return m_instance; }

		void PushCollisionData(const CollisionData& colliData) {
			m_collisions.push_back(std::unique_ptr<const CollisionData>(&colliData));
		}

		void Update() {
			//無効なCollisionDataを削除する
			auto tail_itr = std::remove_if(m_collisions.begin(), m_collisions.end(), [](const auto& colliData) {
				return colliData->IsCanDelete();
			});
			m_collisions.erase(tail_itr, m_collisions.end());

			//あたり判定する
			for (size_t i = 0; i < m_collisions.size();i++) {
				for (size_t j = i+1; j < m_collisions.size();j++) {
					m_collisions[i]->m_collision.HitCheck(m_collisions[j]->m_collision);
				}
			}
		}

		void DebugDraw() {
			for (const auto& item : m_collisions) {
				if(item->IsCanDelete()==false)
					item->m_collision.DebugDraw();
			}
		}
	};
}