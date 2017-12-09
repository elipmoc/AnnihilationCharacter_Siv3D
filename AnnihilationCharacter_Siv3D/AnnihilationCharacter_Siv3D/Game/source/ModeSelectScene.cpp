#include "ModeSelectScene.hpp"
#include "FontObject.hpp"

namespace game {
	ModeSelectScene::ModeSelectScene()
	{
	}

	ModeSelectScene::~ModeSelectScene() = default;

	void ModeSelectScene::init()
	{
		m_gameStartFont = std::make_unique<elipmocframework::FontObject>(L"ゲーム開始");
		m_keyConfigFont = std::make_unique<elipmocframework::FontObject>(L"キー設定");
	}
	void ModeSelectScene::update()
	{
	}
	void ModeSelectScene::draw() const
	{
	}
}