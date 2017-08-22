#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameOverScene.hpp"
#include "GameScene.hpp"
#include "ObjectPool.hpp"
#include "PreObjectPool.hpp"
#include "CollisionControl.hpp"

int elipmocframework::ObjectPoolCount::count=0;


void Main()
{
	siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
	siv::Window::Resize(700, 580);
	game::MySceneManager mySceneManager;
	mySceneManager.add<game::TitleScene>(L"Title");
	mySceneManager.add<game::SelectPlayerScene>(L"SelectPlayer");
	mySceneManager.add<game::GameScene>(L"Game");
	mySceneManager.add<game::GameOverScene>(L"GameOver");

	while (siv::System::Update() && mySceneManager.updateAndDraw()) {
		siv::Println(elipmocframework::ObjectPoolCount::count);
		game::CollisionControl::GetInstance().Update();
		game::CollisionControl::GetInstance().DebugDraw();
	}
}
