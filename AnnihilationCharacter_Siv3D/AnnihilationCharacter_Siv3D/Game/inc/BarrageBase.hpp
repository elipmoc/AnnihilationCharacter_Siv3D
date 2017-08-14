#pragma once
#include <memory>

namespace game {
	class BulletList;

	//�e���N���X
	class BarrageBase {
		//�e���X�g
		std::unique_ptr<BulletList> m_bulletList;
	public:
		BarrageBase(const size_t);
		~BarrageBase();
		virtual void Update() = 0;
	};
}