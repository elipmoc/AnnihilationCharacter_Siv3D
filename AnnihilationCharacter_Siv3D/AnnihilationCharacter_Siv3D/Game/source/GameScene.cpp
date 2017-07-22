#include "GameScene.hpp"
#include "Player.hpp"
#include "TerrainControl.hpp"
#include "HpUI.hpp"
#include "EnemyControl.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	GameScene::~GameScene() = default;

	void GameScene::init()
	{
		m_enemyControl = std::make_unique<EnemyControl>();
		m_terrainControl = std::make_unique<TerrainControl>();
		(m_player= std::make_unique<Player>())
			->SetPos({ 50, 50 }).SetText(m_data->player);
		m_hpUi = std::make_unique<HpUi>();
	}
	void GameScene::update()
	{
	    m_terrainControl->Update();
		m_player->Update2(m_terrainControl);
		m_enemyControl->Update();
	}
	void GameScene::draw() const
	{
		m_player->Draw();
		m_hpUi->Draw();
		m_enemyControl->Draw();
	}
}
