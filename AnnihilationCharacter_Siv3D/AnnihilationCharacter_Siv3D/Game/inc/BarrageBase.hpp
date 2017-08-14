#pragma once
#include <memory>

namespace game {
	class BulletList;

	//弾幕クラス
	class BarrageBase {
		//弾リスト
		std::unique_ptr<BulletList> m_bulletList;
	protected:
		BulletList& GetBulletList();
	public:
		BarrageBase(const size_t);
		~BarrageBase();
		virtual void Update() = 0;
		void Draw()const;
	};
}