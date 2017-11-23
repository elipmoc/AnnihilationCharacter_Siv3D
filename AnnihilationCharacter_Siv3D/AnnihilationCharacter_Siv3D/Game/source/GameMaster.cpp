#include "GameMaster.hpp"
#include "TitleScene.hpp"
#include "LevelSelectScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameOverScene.hpp"
#include "GameScene.hpp"
#include "ObjectPoolUtil.hpp"
#include "CollisionControl.hpp"
#include "LoadFileTerrainData.hpp"
#include "LoadFileEnemyInfo.hpp"
#include "LoadFileConfig.hpp"
#include "EnemyInfo.hpp"



int elipmocframework::ObjectPoolCount::count = 0;

namespace game {


	//インスタンスの実態作成
	GameMaster GameMaster::instance;

	GameMaster::GameMaster()
		:m_mySceneManager(std::make_unique<MySceneManager>()),
		m_loadFileEnemyInfo(std::make_unique<LoadFileEnemyInfo>()),
		m_loadFileConfig(std::make_unique<LoadFileConfig>())
	{
	}

	GameMaster::~GameMaster()
	{
	}

	const TerrainData& GameMaster::GetTerrainData(const std::string& terrainName)const
	{
		return *m_terrainDataMap.at(terrainName);
	}

	const std::vector<std::unique_ptr<EnemyInfo>>& GameMaster::GetEnemyInfoList()const noexcept
	{
		return m_loadFileEnemyInfo->GetEnemyInfoList();
	}

	const size_t GameMaster::GetStartTime() const noexcept
	{
		return m_loadFileConfig->GetStartTime();
	}

	const bool GameMaster::GetShowTimeFlag() const noexcept
	{
		return m_loadFileConfig->GetShowTimeFlag();
	}


	//初期化処理
	bool GameMaster::Init()
	{
		siv::MasterVoice::SetVolume(0.5);

		//アセット用意
		siv::SoundAsset::Register(
			L"bgm",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/MUSIC/bgm.mp3")
		);
		siv::SoundAsset::Register(
			L"決定音",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/決定音.wav")
		);

		siv::SoundAsset::Register(
			L"カーソル音",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/カーソル音.mp3")
		);
		siv::SoundAsset::Register(
			L"shot",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/shot.wav")
		);
		siv::SoundAsset::Register(
			L"バリア",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/バリア.wav")
		);
		siv::SoundAsset::Register(
			L"jump",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/jump.wav")
		);

		//ウインドウ設定
		siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
		siv::Window::Resize(700, 580);

		//シーンセット
		m_mySceneManager->add<TitleScene>(L"Title");
		m_mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		m_mySceneManager->add<LevelSelectScene>(L"LevelSelect");
		m_mySceneManager->add<GameScene>(L"Game");
		m_mySceneManager->add<GameOverScene>(L"GameOver");

		//ファイルデータロード
		try
		{
			m_terrainDataMap["ZakoEnemy"] = LoadFileTerrainData("terrain.txt");
			m_terrainDataMap["Boss1"]=LoadFileTerrainData("BossTerrain1.txt");
			m_loadFileEnemyInfo->LoadFile();
			m_loadFileConfig->LoadFile();
		}
		catch (const siv::String& str)
		{
			siv::MessageBox::Show(str);
			return false;
		}
		return true;
	}

	//ゲームループスタート
	void GameMaster::Start()
	{
		while (siv::System::Update() && m_mySceneManager->updateAndDraw()) {
			//siv::Println(elipmocframework::ObjectPoolCount::count);
			game::CollisionControl::GetInstance().Update();
			siv::PutText(L"fps", siv::Profiler::FPS()).from(50, 0);
			//game::CollisionControl::GetInstance().DebugDraw();
		}
	}

	void GameMaster::End()
	{
	}
}