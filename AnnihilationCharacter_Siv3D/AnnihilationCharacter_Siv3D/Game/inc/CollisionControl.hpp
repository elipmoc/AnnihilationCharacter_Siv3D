#pragma once
#include <memory>
namespace game {

	struct CollisionData;
	//�����蔻��Ǘ��N���X�i�X���b�h�Z�[�t�ȃV���O���g���j
	class CollisionControl {
		CollisionControl()=default;
		static CollisionControl m_instance;

		//�����蔻��̃��X�g
		siv::Array<std::unique_ptr<const CollisionData>> m_collisions;
	public:
		CollisionControl(const CollisionControl&) = delete;
		CollisionControl(CollisionControl&&) = delete;
		~CollisionControl();

		static CollisionControl& GetInstance() { return m_instance; }

		void PushCollisionData(const CollisionData& colliData);

		void Update(); 

		void DebugDraw();
	};
}