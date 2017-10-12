#pragma once
#include "BasePhase.hpp"
namespace game {
	class BulletList;
	class BossPhase :public BasePhase{
		const int m_level;
		BulletList& m_bulletList;
	public:
		BossPhase(int level, const siv::Vec2& playerRefPos, BulletList&);
		~BossPhase();
		virtual void Draw()const override final;
		virtual void Update() override final;

	};
}