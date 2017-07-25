#include "SelectPlayerScene.hpp"
#include "FontObject.hpp"
#include "Actions.hpp"

namespace game {
	using elipmocframework::FontObject;
	using elipmocframework::ScaleAction;

	void SelectPlayerScene::init() {
		using namespace siv::Window;
		//FontObject実体生成してパラメータを設定
		(m_playerFonts[0] = std::make_unique<FontObject>())
			->SetText(L"主").SetPos({ Center().x - 50, Center().y });
		(m_playerFonts[1] = std::make_unique<FontObject>())
			->SetText(L"人").SetPos(Center()).SetScale(10);
		(m_playerFonts[2] = std::make_unique<FontObject>())
			->SetText(L"公").SetPos({ Center().x + 50, Center().y });
	}


	void SelectPlayerScene::update() {

		//enterキーの処理
		if (siv::Input::KeyEnter.clicked) {

			//主人公の文字を設定してシーンを遷移する
			m_data->player = m_playerFonts[m_selectIndex]->GetText();
			changeScene(L"Game");
		}

		//左右キーの処理。押されてたら、文字に拡大縮小アニメーションを設定する
		if ((siv::Input::KeyRight.clicked || siv::Input::KeyLeft.clicked) && m_actionInterval == 0) {
			m_actionInterval = 5;
			m_playerFonts[m_selectIndex]->AddAction(ScaleAction::Create(1, 5));
			if (siv::Input::KeyRight.clicked)
				m_selectIndex = (m_selectIndex + 1) % 3;
			else
				m_selectIndex = (m_selectIndex + 2) % 3;

			m_playerFonts[m_selectIndex]->AddAction(ScaleAction::Create(10, 5));
		}
		if (m_actionInterval != 0)m_actionInterval--;

		//拡大縮小アニメーション更新
		for (auto&& item : m_playerFonts)
			item->Update();

	}


	//文字の描画
	void SelectPlayerScene::draw() const {

		for (const auto& item : m_playerFonts)
			item->DrawCenter();
		m_guideFont(L"主人公を選んでください").draw({ 50,50 });
	}

}