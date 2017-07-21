#include "GameScene.hpp"
#include "Player.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	void GameScene::init()
	{
		m_player= std::make_unique<Player>();
		m_player->SetPos({ 50, 50 }).SetText(m_data->player);
	}
	void GameScene::update()
	{
		m_player->Update();
	}
	void GameScene::draw() const
	{
		m_player->Draw();
	}
}
