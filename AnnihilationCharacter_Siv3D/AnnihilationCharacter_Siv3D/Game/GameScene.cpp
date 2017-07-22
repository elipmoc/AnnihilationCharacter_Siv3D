#include "GameScene.hpp"
#include "Player.hpp"
#include "TerrainControl.hpp"
#include "HpUI.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	void GameScene::init()
	{
		m_terrainControl = std::make_unique<TerrainControl>();
		m_player= std::make_unique<Player>();
		m_player->SetPos({ 50, 50 }).SetText(m_data->player);
		m_hpUi = std::make_unique<HpUi>();
	}
	void GameScene::update()
	{
	    m_terrainControl->Update();
		m_player->Update2(m_terrainControl);
	}
	void GameScene::draw() const
	{
		m_player->Draw();
		m_hpUi->Draw();
	}
}
