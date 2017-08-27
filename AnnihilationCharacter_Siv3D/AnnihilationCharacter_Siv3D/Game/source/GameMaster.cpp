#include "GameMaster.hpp"
#include "TitleScene.hpp"
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


	//インスタンスの実態作成
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


	//初期化処理
	bool GameMaster::Init()
	{
		//ウインドウ設定
		siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
		siv::Window::Resize(700, 580);

		//シーンセット
		m_mySceneManager->add<TitleScene>(L"Title");
		m_mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		m_mySceneManager->add<GameScene>(L"Game");
		m_mySceneManager->add<GameOverScene>(L"GameOver");

		//ファイルデータロード
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

	//ゲームループスタート
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