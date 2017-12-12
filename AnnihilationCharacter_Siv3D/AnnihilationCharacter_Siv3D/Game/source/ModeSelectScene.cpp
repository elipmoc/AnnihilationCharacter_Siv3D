#include "ModeSelectScene.hpp"
#include "FontObject.hpp"
#include "GamePadInput.hpp"
#include "Actions.hpp"

namespace game {
	ModeSelectScene::ModeSelectScene()
	{
	}

	ModeSelectScene::~ModeSelectScene() = default;

	void ModeSelectScene::init()
	{
		using namespace siv::Window;
		m_gameStartFont = std::make_unique<elipmocframework::FontObject>(L"ゲーム開始");
		m_gameStartFont->SetPos({ Center().x, Center().y-20 });
		m_gameStartFont->SetScale(40);
		m_keyConfigFont = std::make_unique<elipmocframework::FontObject>(L"キー設定");
		m_keyConfigFont->SetPos({ Center().x , Center().y+80 });
	}
	void ModeSelectScene::update()
	{
		using namespace elipmocframework;
		if (siv::Input::KeyUp.clicked ||
			siv::Input::KeyDown.clicked ||
			GamePadInput::GetInstance().GetUp() == 1 ||
			GamePadInput::GetInstance().GetDown() == 1) {
			siv::SoundAsset(L"カーソル音").stop();
			siv::SoundAsset(L"カーソル音").play();
			m_selectIndex++;
			if (m_selectIndex % 2 == 0) {
				m_gameStartFont->AddAction(ScaleAction::Create(40, 5));
				m_keyConfigFont->AddAction(ScaleAction::Create(20, 5));
			}
			else {
				m_keyConfigFont->AddAction(ScaleAction::Create(40, 5));
				m_gameStartFont->AddAction(ScaleAction::Create(20, 5));
			}
		}
		if ((siv::Input::KeyZ | GamePadInput::GetInstance().GetJump()).clicked)
		{
			siv::SoundAsset(L"決定音").play();
			if(m_selectIndex%2==0)
				changeScene(L"LevelSelect");
			else changeScene(L"KeyConfig");
		}
		if ((siv::Input::KeyX | GamePadInput::GetInstance().GetBarrier()).clicked)
			changeScene(L"Title");
		m_gameStartFont->Update();
		m_keyConfigFont->Update();
	}
	void ModeSelectScene::draw() const
	{
		m_gameStartFont->DrawCenter();
		m_keyConfigFont->DrawCenter();
	}
}