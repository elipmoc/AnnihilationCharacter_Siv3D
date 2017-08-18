#pragma once
#include <memory>

namespace game {
	class BulletList;

	//弾幕クラス
	class BarrageBase {
		//弾リスト
		std::unique_ptr<BulletList> m_bulletList;

		//弾打つ人の座標
		const siv::Vec2& m_bindPos;
		//弾打つ人の座標修正用
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