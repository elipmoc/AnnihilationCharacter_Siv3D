#include "GameScene.hpp"
#include "Player.hpp"
#include "TerrainControl.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	void GameScene::init()
	{
		m_terrainControl = std::make_unique<TerrainControl>();
		m_player= std::make_unique<Player>();
		m_player->SetPos({ 50, 50 }).SetText(m_data->player);
	}
	void GameScene::update()
	{
	    m_terrainControl->Update();
		m_player->Update();
	}
	void GameScene::draw() const
	{
		m_player->Draw();
	}
}
