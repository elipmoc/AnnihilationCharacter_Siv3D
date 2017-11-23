#pragma once

namespace game {

	class BulletList;

	//力を溜めて放つ主人公の大技
	class PowerBlast {
		//弾リスト
		std::unique_ptr<BulletList> m_bulletList;
		int count = 0;
		//主人公座標の参照
		const siv::Vec2& m_playerPosRef;
		bool m_startFlag=false;
	public:
		PowerBlast(const siv::Vec2& playerPosRef);
		~PowerBlast();
		void Start();
		void Update();
		void Draw()const;
	};

}