#include "LevelSelectScene.hpp"
#include "GlowText.hpp"
#include "Actions.hpp"

namespace game {
	using elipmocframework::GlowText;
	using elipmocframework::MoveAction;

	LevelSelectScene::LevelSelectScene()
		:m_guideFont(20) 
	{
	}

	LevelSelectScene::~LevelSelectScene()
	{
	}

	void LevelSelectScene::init() {
		using namespace siv::Window;
		//FontObject���̐������ăp�����[�^��ݒ�
		(m_levelFonts[0] = std::make_unique<GlowText>(siv::Font(25),L"�́[�܂�",20,1))
			->SetPos({ Center().x, Center().y }).SetColor(siv::Palette::Green).SetGlowColor({ 120,238,120 });
		(m_levelFonts[1] = std::make_unique<GlowText>(siv::Font(25), L"��񂲂�", 20))
			->SetPos({Center().x-50,Center().y+60}).SetColor(siv::Palette::Red).SetGlowColor(siv::Palette::Darkred);
	}


	void LevelSelectScene::update() {

		//enter�L�[�̏���
		if (siv::Input::KeyEnter.clicked) {

			//��l���̕�����ݒ肵�ăV�[����J�ڂ���
		//	m_data->player = m_playerFonts[m_selectIndex]->GetText();
			changeScene(L"SelectPlayer");
		}

		//���E�L�[�̏����B������Ă���A�����Ɋg��k���A�j���[�V������ݒ肷��
		if ((siv::Input::KeyUp.clicked || siv::Input::KeyDown.clicked) && m_actionInterval == 0) {
			m_actionInterval = 5;
			auto pos=m_levelFonts[m_selectIndex]->GetPos();
			m_levelFonts[m_selectIndex]->AddAction(MoveAction::Create(pos + siv::Vec2{-50,0}, 10));
			m_selectIndex = (m_selectIndex + 1) % 2;
			pos = m_levelFonts[m_selectIndex]->GetPos();
			m_levelFonts[m_selectIndex]->AddAction(MoveAction::Create(pos + siv::Vec2{ 50,0 }, 10));
		}
		if (m_actionInterval != 0)m_actionInterval--;

		//�ړ��A�j���[�V�����X�V
		for (auto&& item : m_levelFonts)
			item->Update();

	}


	//�����̕`��
	void LevelSelectScene::draw() const {

		if(m_selectIndex==0)
			siv::Rect(0, m_levelFonts[0]->GetPos().y - 14, siv::Window::Width(), 30).draw({0,200,50,20});
		else
			siv::Rect(0, m_levelFonts[1]->GetPos().y - 14, siv::Window::Width(), 30).draw({ 200,0,50,20 });
		for (const auto& item : m_levelFonts)
			item->DrawCenter();
		m_guideFont(L"��Փx��I��ł�������").draw({ 50,50 });
		
	}

}