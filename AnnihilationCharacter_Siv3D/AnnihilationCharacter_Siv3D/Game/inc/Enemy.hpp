#pragma once

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class CollisionCircle;
	class BarrageBase;
	struct EnemyModelInfo;
	class Enemy{
	protected:
		//�e��
		std::unique_ptr<BarrageBase> m_barrage;
		//�G�̕���
		std::unique_ptr<elipmocframework::FontObject> m_enemyFont;
		//�G�����蔻��
		std::unique_ptr<CollisionCircle> m_collision;
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