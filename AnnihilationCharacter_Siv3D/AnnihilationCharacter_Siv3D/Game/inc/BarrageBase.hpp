#pragma once
#include <memory>

namespace game {
	class BulletList;

	//�e���N���X
	class BarrageBase {
		//�e���X�g
		std::unique_ptr<BulletList> m_bulletList;

		//�e�łl�̍��W
		const siv::Vec2& m_bindPos;
		//�e�łl�̍��W�C���p
		const siv::Vec2 m_fixPos;
	protected:

		BulletList& GetBulletList();

		siv::Vec2 GetPos()const noexcept {
			return m_bindPos + m_fixPos;
		}

	public:
		BarrageBase(const size_t, const siv::Vec2& bindPos, const siv::Vec2& fixPos = {0,0});
		~BarrageBase();
		virtual void Update() = 0;
		void Draw()const;
	};
}