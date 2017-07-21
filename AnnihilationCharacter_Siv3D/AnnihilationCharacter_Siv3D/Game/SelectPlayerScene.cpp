#include "SelectPlayerScene.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;
	using elipmocframework::CreateScaleAction;

	void SelectPlayerScene::init() {
		using namespace siv::Window;
		//FontObject実体生成してパラメータを設定
		(playerFonts[0] = std::make_unique<FontObject>())
			->SetText(L"主").SetPos({ Center().x - 50, Center().y });
		(playerFonts[1] = std::make_unique<FontObject>())
			->SetText(L"人").SetPos(Center()).SetScale(10);
		(playerFonts[2] = std::make_unique<FontObject>())
			->SetText(L"公").SetPos({ Center().x + 50, Center().y });
	}


	void SelectPlayerScene::update() {

		//enterキーの処理
		if (siv::Input::KeyEnter.clicked) {

			//主人公の文字を設定してシーンを遷移する
			m_data->player = playerFonts[selectIndex]->GetText();
			changeScene(L"Game");
		}

		//左右キーの処理。押されてたら、文字に拡大縮小アニメーションを設定する
		if ((siv::Input::KeyRight.clicked || siv::Input::KeyLeft.clicked) && actionInterval == 0) {
			actionInterval = 5;
			playerFonts[selectIndex]->AddAction(CreateScaleAction(*playerFonts[selectIndex], 1, 5));
			if (siv::Input::KeyRight.clicked)
				selectIndex = (selectIndex + 1) % 3;
			else
				selectIndex = (selectIndex + 2) % 3;

			playerFonts[selectIndex]->AddAction(CreateScaleAction(*playerFonts[selectIndex], 10, 5));
		}
		if (actionInterval != 0)actionInterval--;

		//拡大縮小アニメーション更新
		for (auto&& item : playerFonts)
			item->Update();

	}


	//文字の描画
	void SelectPlayerScene::draw() const {

		for (const auto& item : playerFonts)
			item->DrawCenter();
		guideFont(L"主人公を選んでください").draw({ 50,50 });
	}

}