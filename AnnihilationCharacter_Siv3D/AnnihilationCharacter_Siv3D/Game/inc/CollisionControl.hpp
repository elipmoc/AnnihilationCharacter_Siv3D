#pragma once
#include <memory>
namespace game {

	struct CollisionData;
	//あたり判定管理クラス（スレッドセーフなシングルトン）
	class CollisionControl {
		CollisionControl()=default;
		static CollisionControl m_instance;

		//あたり判定のリスト
		siv::Array<std::unique_ptr<const CollisionData>> m_collisions;
	public:
		CollisionControl(const CollisionControl&) = delete;
		CollisionControl(CollisionControl&&) = delete;
		~CollisionControl()noexcept;

		static CollisionControl& GetInstance()noexcept{ return m_instance; }

		void PushCollisionData(const CollisionData& colliData);

		void Update(); 

		void DebugDraw();
	};
}