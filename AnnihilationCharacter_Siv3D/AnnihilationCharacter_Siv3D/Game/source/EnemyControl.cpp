#include "EnemyControl.hpp"
#include "EnemyList.hpp"
#include "TestEnemyAction.hpp"
#include "TestBarrage.hpp"
#include "FontObject.hpp"
#include "Enemy.hpp"
#include "TestEnemyModelInfoGenerator.hpp"

namespace game {
	using elipmocframework::FontObject;
	EnemyControl::EnemyControl():m_enemyList(std::make_unique<EnemyList>())
	{
		auto&& enemyFont = std::make_unique < FontObject>();
		m_enemyList->push_back(
			std::make_unique<Enemy>(
				TestEnemyModelInfoGenerator().GenerateEnemyModelInfo(),
				std::make_unique<TestBarrage>(enemyFont->GetRefPos()),
				std::make_unique<TestEnemyAction>(enemyFont,siv::Vec2{ 800,500 }, siv::Vec2{ 100,200 }, siv::Vec2{ 400,20 }),
				std::move(enemyFont)
			)
		);
	}
	EnemyControl::~EnemyControl() = default;
	void EnemyControl::Draw() const
	{
		m_enemyList->Draw();
	}
	void EnemyControl::Update()
	{
		m_enemyList->Update();
	}
}
