#include "ModeSelectScene.hpp"
#include "FontObject.hpp"

namespace game {
	ModeSelectScene::ModeSelectScene()
	{
	}

	ModeSelectScene::~ModeSelectScene() = default;

	void ModeSelectScene::init()
	{
		m_gameStartFont = std::make_unique<elipmocframework::FontObject>(L"�Q�[���J�n");
		m_keyConfigFont = std::make_unique<elipmocframework::FontObject>(L"�L�[�ݒ�");
	}
	void ModeSelectScene::update()
	{
	}
	void ModeSelectScene::draw() const
	{
	}
}