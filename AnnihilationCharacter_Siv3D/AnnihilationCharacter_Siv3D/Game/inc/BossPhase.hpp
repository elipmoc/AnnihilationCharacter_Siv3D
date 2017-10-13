#pragma once
#include "BasePhase.hpp"
#include "SceneBase.hpp"
namespace game {
	class BulletList;
	class BossPhase :public BasePhase{
		const Level m_level;
		BulletList& m_bulletList;
	public:
		BossPhase(Level level, const siv::Vec2& playerRefPos, BulletList&);
		~BossPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}