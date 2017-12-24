#include "GameScene.hpp"
#include "Player.hpp"
#include "TerrainControl.hpp"
#include "HpUI.hpp"
#include "BarrierUI.hpp"
#include "EnemyPhaseControl.hpp"
#include "GameCounter.hpp"
#include "GameMaster.hpp"
#include "PowerGage.hpp"
namespace game {
	GameScene::GameScene():m_player(nullptr) {

	}

	GameScene::~GameScene() = default;

	void GameScene::init()
	{
		siv::SoundAsset(L"bgm").setLoop(true);
		siv::SoundAsset(L"bgm").setVolume(0.3);
		siv::SoundAsset(L"bgm").play();
		m_gameCounter = std::make_unique<GameCounter>(GameMaster::GetInstance().GetStartTime());
		m_terrainControl = std::make_unique<TerrainControl>(GameMaster::GetInstance().GetTerrainData("ZakoEnemy"),m_gameCounter->GetCount());
		(m_player= std::make_unique<Player>())
			->SetPos({ 50, 50 }).SetText(m_data->player);
		m_enemyControl = std::make_unique<EnemyPhaseControl>(m_data->level,m_player->GetRefPos(), *m_gameCounter,*m_terrainControl);
		m_hpUi = std::make_unique<HpUi>();
		m_barrierUi = std::make_unique<BarrierUi>();
		m_powerGage = std::make_unique<PowerGage>(Player::MAX_POWERNUM);
	}

	void GameScene::SetSlow() {
		if (m_slowFlag)return;
		m_slowFlag = true;
		m_slowCount = 0;
	}

	void GameScene::UnSetSlow() {
		m_slowFlag = false;
	}

	void GameScene::update()
	{
		if (m_player->GetHp() == 0)
			changeScene(L"GameOver");
		if (m_enemyControl->IsClear())
			changeScene(L"Clear");
		if (m_player->IsPlayerDeadStarted())
			SetSlow();
		else UnSetSlow();
		if (m_slowFlag==false || m_slowCount % 6 == 0) {
			m_terrainControl->Update();
			m_player->Update2(m_terrainControl);
			m_enemyControl->Update();
			m_gameCounter->CountDown();

		}
		m_player->BarrierButtonUpdate();
		m_slowCount++;
	}
	void GameScene::draw() const
	{
		m_player->DrawCenter();
		m_powerGage->Draw(m_player->GetPowerNum());
		m_hpUi->Draw(m_player->GetHp());
		m_barrierUi->Draw(m_player->GetBarrierCount());
		m_enemyControl->Draw();
		if(GameMaster::GetInstance().GetShowTimeFlag())
		siv::PutText(L"Time:", m_gameCounter->GetCount()).from(siv::Window::Width()-100, 0);
	}
}
