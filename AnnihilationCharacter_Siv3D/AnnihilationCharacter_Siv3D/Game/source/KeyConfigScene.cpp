#include "KeyConfigScene.hpp"
#include "FontObject.hpp"
#include "GamePadInput.hpp"
#include "Actions.hpp"
#include "GamePadInput.hpp"

namespace game {
	KeyConfigScene::KeyConfigScene() = default;
	KeyConfigScene::~KeyConfigScene() = default;

	void KeyConfigScene::draw() const
	{
		for (size_t i = 0; i < 3; i++) {
			m_keyName[i]->DrawCenter();
		}
	}
	void KeyConfigScene::update()
	{
		using namespace elipmocframework;

		if (siv::Input::KeyUp.clicked ||
			siv::Input::KeyDown.clicked ||
			GamePadInput::GetInstance().GetUp() == 1 ||
			GamePadInput::GetInstance().GetDown() == 1) {
			siv::SoundAsset(L"カーソル音").stop();
			siv::SoundAsset(L"カーソル音").play();
			m_keyName[m_selectIndex]->AddAction(ScaleAction::Create(20, 5));
			if (siv::Input::KeyDown.clicked || GamePadInput::GetInstance().GetDown() == 1)
				m_selectIndex++;
			else
				m_selectIndex += 2;
			m_selectIndex %= 3;
			m_keyName[m_selectIndex]->AddAction(ScaleAction::Create(40, 5));
		}
		if ((siv::Input::KeyX | GamePadInput::GetInstance().GetBarrier()).clicked)
			changeScene(L"ModeSelect");

		for (size_t i = 0; i < 3; i++) {
			m_keyName[i]->Update();
		}

	}
	void KeyConfigScene::init()
	{
		m_gamePadData = std::make_unique<GamePadData>(GamePadInput::GetInstance().GetGamePadData());
		siv::String str[] = { L"ジャンプ:",L"バリア:",L"ふわり:" };
		using namespace siv::Window;
		for (size_t i = 0; i < 3; i++) {
			m_keyName[i] = std::make_unique<elipmocframework::FontObject>(str[i]);
			m_keyName[i]->SetPos({ Center().x-150, Center().y-100 + 80*i });
		}
		m_keyName[0]->SetScale(30);
	}
}