#pragma once

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class BarrageBase;
	struct EnemyModelInfo;
	class Enemy{
	protected:
		//’e–‹
		std::unique_ptr<BarrageBase> m_barrage;
		
		std::unique_ptr<elipmocframework::FontObject> m_enemyFont;
	public:
		Enemy(
			const EnemyModelInfo& info,
			std::unique_ptr<BarrageBase>&&,
			std::unique_ptr<elipmocframework::FontObject>&&);
		void Draw()const;
		void Update();
		~Enemy();
	};
}