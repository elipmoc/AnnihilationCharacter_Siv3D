#include "TitleScene.hpp"

void Main()
{
	siv::Window::SetTitle(L"消滅文字 ver 114524");
	siv::Window::Resize(700, 480);
	game::MySceneManager mySceneManager;
	mySceneManager.add<game::TitleScene>(L"Title");
	while (siv::System::Update() && mySceneManager.updateAndDraw());
}
