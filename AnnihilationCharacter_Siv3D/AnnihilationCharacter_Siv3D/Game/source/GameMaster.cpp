#include "GameMaster.hpp"
#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameOverScene.hpp"
#include "GameScene.hpp"
#include "ObjectPoolUtil.hpp"
#include "CollisionControl.hpp"
#include "LoadFileTerrainData.hpp"



int elipmocframework::ObjectPoolCount::count = 0;

namespace game {


	//インスタンスの実態作成
	GameMaster GameMaster::instance;

	GameMaster::GameMaster()
		:mySceneManager(std::make_unique<MySceneManager>())
	{
	}

	GameMaster::~GameMaster()
	{
	}

	//初期化処理
	void GameMaster::Init()
	{
		//ウインドウ設定
		siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
		siv::Window::Resize(700, 580);

		//シーンセット
		mySceneManager->add<TitleScene>(L"Title");
		mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		mySceneManager->add<GameScene>(L"Game");
		mySceneManager->add<GameOverScene>(L"GameOver");

		//地形データロード
		LoadFileTerrainData terrainData;
		try
		{
			terrainData.LoadFile();
		}
		catch (const siv::String& str)
		{
			siv::MessageBox::Show(str);
			return;
		}
	}

	//ゲームループスタート
	void GameMaster::Start()
	{
		while (siv::System::Update() && mySceneManager->updateAndDraw()) {
			siv::Println(elipmocframework::ObjectPoolCount::count);
			game::CollisionControl::GetInstance().Update();
			game::CollisionControl::GetInstance().DebugDraw();
		}
	}

	void GameMaster::End()
	{
	}
}