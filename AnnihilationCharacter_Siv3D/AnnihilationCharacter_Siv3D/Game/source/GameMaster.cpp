#include "GameMaster.hpp"
#include "TitleScene.hpp"
#include "LevelSelectScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameOverScene.hpp"
#include "GameScene.hpp"
#include "ClearScene.hpp"
#include "ObjectPoolUtil.hpp"
#include "CollisionControl.hpp"
#include "LoadFileTerrainData.hpp"
#include "LoadFileEnemyInfo.hpp"
#include "LoadFileConfig.hpp"
#include "EnemyInfo.hpp"
#include "GamePadConfigLoader.hpp"
#include "GamePadInput.hpp"
#include "ModeSelectScene.hpp"


int elipmocframework::ObjectPoolCount::count = 0;

namespace game {


	//�C���X�^���X�̎��ԍ쐬
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


	//����������
	bool GameMaster::Init()
	{
		siv::MasterVoice::SetVolume(0.5);

		//�A�Z�b�g�p��
		siv::SoundAsset::Register(
			L"bgm",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/MUSIC/bgm.mp3")
		);
		siv::SoundAsset::Register(
			L"���艹",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/���艹.wav")
		);

		siv::SoundAsset::Register(
			L"�J�[�\����",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/�J�[�\����.mp3")
		);
		siv::SoundAsset::Register(
			L"shot",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/shot.wav")
		);
		siv::SoundAsset::Register(
			L"�o���A",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/�o���A.wav")
		);
		siv::SoundAsset::Register(
			L"jump",
			siv::SoundAssetData::FromFileArchive(L"/810", L"Resource/SE/jump.wav")
		);

		//�E�C���h�E�ݒ�
		siv::Window::SetTitle(L"���ŕ��� ver 1919810114514");
		siv::Window::Resize(700, 580);

		//�V�[���Z�b�g
		m_mySceneManager->add<TitleScene>(L"Title");
		m_mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		m_mySceneManager->add<LevelSelectScene>(L"LevelSelect");
		m_mySceneManager->add<GameScene>(L"Game");
		m_mySceneManager->add<GameOverScene>(L"GameOver");
		m_mySceneManager->add<ClearScene>(L"Clear");
		m_mySceneManager->add<ModeSelectScene>(L"ModeSelect");
		//�t�@�C���f�[�^���[�h
		try
		{
			GamePadConfigLoader gpcl;
			GamePadInput::GetInstance().LoadGamePadData(gpcl.Load(L"gamePadConfig.json"));
			m_terrainDataMap["ZakoEnemy"] = LoadFileTerrainData("terrain.txt");
			m_terrainDataMap["Boss1"] = LoadFileTerrainData("BossTerrain1.txt");
			m_terrainDataMap["Boss2"]=LoadFileTerrainData("BossTerrain2.txt");
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

	//�Q�[�����[�v�X�^�[�g
	void GameMaster::Start(){
		while (siv::System::Update() && m_mySceneManager->updateAndDraw()) {
			game::GamePadInput::GetInstance().Update();
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