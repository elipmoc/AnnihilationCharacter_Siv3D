#include "GameScene.hpp"
#include "Player.hpp"
#include "TerrainControl.hpp"
#include "HpUI.hpp"
#include "BarrierUI.hpp"
#include "EnemyControl.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	GameScene::~GameScene() = default;

	void GameScene::init()
	{
		siv::SoundAsset(L"bgm").setLoop(true);
		siv::SoundAsset(L"bgm").setVolume(0.1);
		siv::SoundAsset(L"bgm").play();
		m_terrainControl = std::make_unique<TerrainControl>();
		(m_player= std::make_unique<Player>())
			->SetPos({ 50, 50 }).SetText(m_data->player);
		m_enemyControl = std::make_unique<EnemyControl>(m_data->level,m_player->GetRefPos());
		m_hpUi = std::make_unique<HpUi>();
		m_barrierUi = std::make_unique<BarrierUi>();
	}
	void GameScene::update()
	{
		if (m_player->GetHp() == 0)
			changeScene(L"GameOver");
		if (m_terrainControl->IsFinished())
			changeScene(L"GameOver");
	    m_terrainControl->Update();
		m_player->Update2(m_terrainControl);
		m_enemyControl->Update();
	}
	void GameScene::draw() const
	{
		m_player->DrawCenter();
		m_hpUi->Draw(m_player->GetHp());
		m_barrierUi->Draw(m_player->GetBarrierCount());
		m_enemyControl->Draw();
	}
}
