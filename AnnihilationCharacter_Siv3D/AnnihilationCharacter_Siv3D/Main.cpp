#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"
#include "CollisionControl.hpp"
#include "CollisionCircle.hpp"
#include "Bullet.hpp"
#include "type_traits_original.hpp"
#include "pack_traits_original.hpp"
#include "ObjectPool.hpp"
#include "Barrage.hpp"

void Main()
{
	game::CollisionCircle c({ 300,100 }, [](game::CollisionID) {});
	c.SetR(50);
	c.SetCollisionID(game::CollisionID::EnemyID);
	siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
	siv::Window::Resize(700, 580);
	game::MySceneManager mySceneManager;
	mySceneManager.add<game::TitleScene>(L"Title");
	mySceneManager.add<game::SelectPlayerScene>(L"SelectPlayer");
	mySceneManager.add<game::GameScene>(L"Game");
	while (siv::System::Update() && mySceneManager.updateAndDraw()) {
		game::CollisionControl::GetInstance().Update();
		game::CollisionControl::GetInstance().DebugDraw();
	}
}
