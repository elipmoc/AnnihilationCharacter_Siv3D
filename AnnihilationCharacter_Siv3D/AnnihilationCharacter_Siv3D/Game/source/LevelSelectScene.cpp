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
		//FontObject実体生成してパラメータを設定
		(m_levelFonts[0] = std::make_unique<GlowText>(siv::Font(25),L"のーまる",20,1))
			->SetPos({ Center().x, Center().y }).SetColor(siv::Palette::Green).SetGlowColor({ 120,238,120 });
		(m_levelFonts[1] = std::make_unique<GlowText>(siv::Font(25), L"れんごく", 20))
			->SetPos({Center().x-50,Center().y+60}).SetColor(siv::Palette::Red).SetGlowColor(siv::Palette::Darkred);
	}


	void LevelSelectScene::update() {

		//enterキーの処理
		if (siv::Input::KeyZ.clicked) {

			//難易度を設定してシーンを遷移する
			m_data->level = static_cast<Level>(m_selectIndex);
			changeScene(L"SelectPlayer");
		}

		//上下キーの処理。押されてたら、文字に拡大縮小アニメーションを設定する
		if ((siv::Input::KeyUp.clicked || siv::Input::KeyDown.clicked) && m_actionInterval == 0) {
			m_actionInterval = 5;
			auto pos=m_levelFonts[m_selectIndex]->GetPos();
			m_levelFonts[m_selectIndex]->AddAction(MoveAction::Create(pos + siv::Vec2{-50,0}, 10));
			m_selectIndex = (m_selectIndex + 1) % 2;
			pos = m_levelFonts[m_selectIndex]->GetPos();
			m_levelFonts[m_selectIndex]->AddAction(MoveAction::Create(pos + siv::Vec2{ 50,0 }, 10));
		}
		if (m_actionInterval != 0)m_actionInterval--;

		//移動アニメーション更新
		for (auto&& item : m_levelFonts)
			item->Update();

	}


	//文字の描画
	void LevelSelectScene::draw() const {

		if(m_selectIndex==0)
			siv::Rect(0, m_levelFonts[0]->GetPos().y - 14, siv::Window::Width(), 30).draw({0,200,50,20});
		else
			siv::Rect(0, m_levelFonts[1]->GetPos().y - 14, siv::Window::Width(), 30).draw({ 200,0,50,20 });
		for (const auto& item : m_levelFonts)
			item->DrawCenter();
		m_guideFont(L"難易度を選んでください").draw({ 50,50 });
		
	}

}