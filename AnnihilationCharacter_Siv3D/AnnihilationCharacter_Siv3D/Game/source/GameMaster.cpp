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
#include "EnemyInfo.hpp"



int elipmocframework::ObjectPoolCount::count = 0;

namespace game {


	//�C���X�^���X�̎��ԍ쐬
	GameMaster GameMaster::instance;

	GameMaster::GameMaster()
		:m_mySceneManager(std::make_unique<MySceneManager>()),
		m_loadFileTerrainData(std::make_unique<LoadFileTerrainData>()),
		m_loadFileEnemyInfo(std::make_unique<LoadFileEnemyInfo>())
	{
	}

	GameMaster::~GameMaster()
	{
	}

	const std::vector<bool>& GameMaster::GetTerrainData(size_t lane)const noexcept
	{
		return m_loadFileTerrainData->GetTerrainData(lane);
	}

	const std::vector<std::unique_ptr<EnemyInfo>>& GameMaster::GetEnemyInfoList()const noexcept
	{
		return m_loadFileEnemyInfo->GetEnemyInfoList();
	}


	//����������
	bool GameMaster::Init()
	{
		//�E�C���h�E�ݒ�
		siv::Window::SetTitle(L"���ŕ��� ver 1919810114514");
		siv::Window::Resize(700, 580);

		//�V�[���Z�b�g
		m_mySceneManager->add<TitleScene>(L"Title");
		m_mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		m_mySceneManager->add<LevelSelectScene>(L"LevelSelect");
		m_mySceneManager->add<GameScene>(L"Game");
		m_mySceneManager->add<GameOverScene>(L"GameOver");

		//�t�@�C���f�[�^���[�h
		try
		{
			m_loadFileTerrainData->LoadFile();
			m_loadFileEnemyInfo->LoadFile();
		}
		catch (const siv::String& str)
		{
			siv::MessageBox::Show(str);
			return false;
		}
		return true;
	}

	//�Q�[�����[�v�X�^�[�g
	void GameMaster::Start()
	{
		while (siv::System::Update() && m_mySceneManager->updateAndDraw()) {
			siv::Println(elipmocframework::ObjectPoolCount::count);
			game::CollisionControl::GetInstance().Update();
			game::CollisionControl::GetInstance().DebugDraw();
		}
	}

	void GameMaster::End()
	{
	}
}