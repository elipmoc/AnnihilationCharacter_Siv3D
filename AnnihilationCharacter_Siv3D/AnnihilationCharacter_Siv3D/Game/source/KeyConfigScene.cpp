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
			m_keyCode[i]->DrawCenter();
		}
		m_decision->DrawCenter();
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

			if (m_selectIndex == 3)
				m_decision->AddAction(ScaleAction::Create(20, 5));
			else
			{
				m_keyName[m_selectIndex]->AddAction(ScaleAction::Create(20, 5));
				m_keyCode[m_selectIndex]->AddAction(ScaleAction::Create(20, 5));
			}

			if (siv::Input::KeyDown.clicked || GamePadInput::GetInstance().GetDown() == 1)
				m_selectIndex++;
			else
				m_selectIndex += 3;
			m_selectIndex %= 4;

			if (m_selectIndex == 3)
				m_decision->AddAction(ScaleAction::Create(40, 5));
			else
			{
				m_keyName[m_selectIndex]->AddAction(ScaleAction::Create(40, 5));
				m_keyCode[m_selectIndex]->AddAction(ScaleAction::Create(40, 5));
			}
		}

		if (m_selectIndex != 3) {
			for (size_t i = 0; i < siv::Gamepad(0).num_buttons; i++) {
				if (siv::Gamepad(0).button(i).clicked) {

					for (size_t ii = 0; ii < 3; ii++) {
						if (m_selectIndex != ii &&
							reinterpret_cast<unsigned int*>(m_gamePadData.get())[ii] == i) {
							m_keyCode[ii]->SetText(siv::Format(reinterpret_cast<unsigned int*>(m_gamePadData.get())[m_selectIndex]));
							reinterpret_cast<unsigned int*>(m_gamePadData.get())[ii] =
								reinterpret_cast<unsigned int*>(m_gamePadData.get())[m_selectIndex];
							break;
						}
					}
					m_keyCode[m_selectIndex]->SetText(siv::Format(i));
					reinterpret_cast<unsigned int*>(m_gamePadData.get())[m_selectIndex] = i;
				}
			}
		}

		for (size_t i = 0; i < 3; i++) {
			m_keyName[i]->Update();
			m_keyCode[i]->Update();
		}
		m_decision->Update();

		if (m_selectIndex == 3 && (siv::Input::KeyZ.clicked || GamePadInput::GetInstance().GetJump().clicked)) {

			try {
				auto gpcl = GamePadConfigLoader();
				gpcl.Save(*m_gamePadData, L"gamePadConfig.json");
				GamePadInput::GetInstance().LoadGamePadData(gpcl.Load(L"gamePadConfig.json"));
			}
			catch (const siv::String& str)
			{
				siv::MessageBox::Show(str);
			}
			changeScene(L"ModeSelect");
		}


	}
	void KeyConfigScene::init()
	{
		m_gamePadData = std::make_unique<GamePadData>(GamePadInput::GetInstance().GetGamePadData());
		siv::String str[] = { L"ジャンプ:",L"バリア:",L"ふわり:" };
		using namespace siv::Window;
		for (size_t i = 0; i < 3; i++) {
			m_keyName[i] = std::make_unique<elipmocframework::FontObject>(str[i]);
			m_keyCode[i] = std::make_unique<elipmocframework::FontObject>(siv::Format(reinterpret_cast<unsigned int*>(m_gamePadData.get())[i]));
			m_keyName[i]->SetPos({ Center().x - 150, Center().y - 100 + 80 * i });
			m_keyCode[i]->SetPos({ Center().x, Center().y-100 + 80*i });
		}
		m_decision = std::make_unique<elipmocframework::FontObject>(L"設定する");
		m_decision->SetPos({ Center().x - 150, Center().y - 100 + 80 * 4 });
		m_keyName[0]->SetScale(30);
		m_keyCode[0]->SetScale(30);
	}
}