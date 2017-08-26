#pragma once
#include "Interface.hpp"

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class CollisionCircle;
	class BarrageBase;
	struct EnemyModelInfo;
	class Enemy:public elipmocframework::has_delete_flag{
	protected:
		//�e��
		std::unique_ptr<BarrageBase> m_barrage;
		//�G�̕���
		std::unique_ptr<elipmocframework::FontObject> m_enemyFont;
		//�G�����蔻��
		std::unique_ptr<CollisionCircle> m_collision;
		//��������
		int m_lifeTime;
	public:
		Enemy(
			int lifeTime,
			const EnemyModelInfo& info,
			std::unique_ptr<BarrageBase>&&,
			std::unique_ptr<elipmocframework::FontObject>&&);
		void Draw()const;
		void Update();
		~Enemy();
	};
}