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
	game::ParticleList particleList;
	particleList.AddParticle(game::ParticleBase::Create(L"破", { 300,300 }, 3000, 500, 10, 1, 0.001, { 255,255,255,255 }, -0.4, 50, 20, {0,0}));
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
