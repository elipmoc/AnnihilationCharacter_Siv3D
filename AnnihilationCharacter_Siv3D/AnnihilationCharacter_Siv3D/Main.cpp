#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"
#include "CollisionControl.hpp"
#include "ParticleList.hpp"
#include "ParticleBase.hpp"
#include "ParticleFontObject.hpp"

void Main()
{
	game::ParticleList particleList;
	particleList.AddParticle(game::ParticleBase::Create(L"破", { 200,200 }, 3000, 200, 20, 1, 0.2, { 255,255,255,255 }, -1, 20, 20, {0,0.23}));
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
