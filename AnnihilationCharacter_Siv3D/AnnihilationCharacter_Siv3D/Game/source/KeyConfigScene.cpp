#include "KeyConfigScene.hpp"
#include "FontObject.hpp"

namespace game {
	void KeyConfigScene::draw() const
	{
		for (size_t i = 0; i < 3; i++) {
			m_keyName[i]->DrawCenter();
		}
	}
	void KeyConfigScene::update()
	{

	}
	void KeyConfigScene::init()
	{
		siv::String str[] = { L"ジャンプ:",L"バリア:",L"ふわり:" };
		using namespace siv::Window;
		for (size_t i = 0; i < 3; i++) {
			m_keyName[i] = std::make_unique<elipmocframework::FontObject>(str[i]);
			m_keyName[i]->SetPos({ Center().x-150, Center().y-100 + 80*i });
		}
	}
}