#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"
#include "CollisionControl.hpp"
#include "ParticleList.hpp"



void Main()
{
	elipmocframework::ParticleState state;
	state.lifeTime = 200;
	state.particleLifeTime = 200;
	state.particleNum = 10;
	state.particleMaxNum = 10;
	state.speed = 2;
	state.vspeed = 0.0001;
	state.fireInterval = 100;
	state.text = L"消";
	state.vopacity = -2.5;
	elipmocframework::ParticleList particleList(40, state);
	state.text = L"滅";
	elipmocframework::ParticleList particleList2(40, state);
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
