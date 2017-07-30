#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"
#include "CollisionControl.hpp"
#include "ParticleList.hpp"
#include "ParticleBase.hpp"
#include "ParticleFontObject.hpp"
#include "ObjectPool.hpp"


void Main()
{
	elipmocframework::ObjectPool<int> o(3);
	o.New(45);
	o.New(25);
	o.New(15);
	o.DeleteAt(1);
	o.New(25);
	for(auto&& item:o)
		siv::Println(item);
	game::ParticleList particleList;
	particleList.AddParticle(game::ParticleBase::Create(L"破", { 300,300 }, 3000, 120, 20, 1, 0.1, { 255,255,255,255 }, -0.2, 1, 20, {0,0}));
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
		particleList.Draw();
	}
}
