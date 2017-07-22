#include "SelectPlayerScene.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;
	using elipmocframework::CreateScaleAction;

	void SelectPlayerScene::init() {
		using namespace siv::Window;
		//FontObject���̐������ăp�����[�^��ݒ�
		(m_playerFonts[0] = std::make_unique<FontObject>())
			->SetText(L"��").SetPos({ Center().x - 50, Center().y });
		(m_playerFonts[1] = std::make_unique<FontObject>())
			->SetText(L"�l").SetPos(Center()).SetScale(10);
		(m_playerFonts[2] = std::make_unique<FontObject>())
			->SetText(L"��").SetPos({ Center().x + 50, Center().y });
	}


	void SelectPlayerScene::update() {

		//enter�L�[�̏���
		if (siv::Input::KeyEnter.clicked) {

			//��l���̕�����ݒ肵�ăV�[����J�ڂ���
			m_data->player = m_playerFonts[m_selectIndex]->GetText();
			changeScene(L"Game");
		}

		//���E�L�[�̏����B������Ă���A�����Ɋg��k���A�j���[�V������ݒ肷��
		if ((siv::Input::KeyRight.clicked || siv::Input::KeyLeft.clicked) && m_actionInterval == 0) {
			m_actionInterval = 5;
			m_playerFonts[m_selectIndex]->AddAction(CreateScaleAction(*m_playerFonts[m_selectIndex], 1, 5));
			if (siv::Input::KeyRight.clicked)
				m_selectIndex = (m_selectIndex + 1) % 3;
			else
				m_selectIndex = (m_selectIndex + 2) % 3;

			m_playerFonts[m_selectIndex]->AddAction(CreateScaleAction(*m_playerFonts[m_selectIndex], 10, 5));
		}
		if (m_actionInterval != 0)m_actionInterval--;

		//�g��k���A�j���[�V�����X�V
		for (auto&& item : m_playerFonts)
			item->Update();

	}


	//�����̕`��
	void SelectPlayerScene::draw() const {

		for (const auto& item : m_playerFonts)
			item->DrawCenter();
		m_guideFont(L"��l����I��ł�������").draw({ 50,50 });
	}

}