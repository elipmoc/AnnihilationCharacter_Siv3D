#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"
#include "CollisionControl.hpp"
#include "ParticleList.hpp"



void Main()
{
	elipmocframework::ParticleList particleList(40, L"消", 200, 200, 10, 2, 0.001, siv::Color{ 255,255,255,255 }, -2.5, 100, 20, siv::Vec2{ 0,0 });
	elipmocframework::ParticleList particleList2(40,L"滅", 200, 200, 10, 2, 0.001, siv::Color{ 255,255,255,255 }, -2.5, 100, 20, siv::Vec2{0,0});
	siv::Window::SetTitle(L"消滅文字 ver 1919810114514");
	siv::Window::Resize(700, 580);
	game::MySceneManager mySceneManager;
	mySceneManager.add<game::TitleScene>(L"Title");
	mySceneManager.add<game::SelectPlayerScene>(L"SelectPlayer");
	mySceneManager.add<game::GameScene>(L"Game");
	while (siv::System::Update() && mySceneManager.updateAndDraw()) {
		game::CollisionControl::GetInstance().Update();
		game::CollisionControl::GetInstance().DebugDraw();
		particleList.Update();
		particleList2.Update();
		particleList.Draw();
		particleList2.Draw();
		if (siv::Random(1, 100) == 5)
			if(siv::Random(1,2)==1)
				particleList.Set({siv::Random(0,700),siv::Random(0,580) });
			else 
				particleList2.Set({ siv::Random(0,700),siv::Random(0,580) });
	}
}
