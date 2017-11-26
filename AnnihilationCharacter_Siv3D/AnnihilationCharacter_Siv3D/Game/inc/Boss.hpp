#pragma once
#include "SceneBase.hpp"

namespace elipmocframework {
	class FontObject;

}

namespace game {
	class BulletListCreator;
	class BossBehavior;
	class CollisionCircle;

	//�{�X�N���X
	class Boss {
		std::unique_ptr<BossBehavior> m_bossBehavior;
		const Level m_level;
		size_t m_hp;
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
		std::unique_ptr<elipmocframework::FontObject> m_fontObject;
		std::unique_ptr<CollisionCircle> m_collision;
		const siv::Vec2& m_playerRefPos;
		
	public:
		static constexpr siv::Vec2 BOSS_POS = { 570, 160 };
		Boss(Level level,const siv::Vec2& playerRefPos, BulletListCreator&);
		~Boss();
		size_t GetHp() { return m_hp; }
		size_t SetHp(size_t hp) { return m_hp = hp; }
		void SetBossBehavior();
		void Update();
		void Draw()const;
	};

}