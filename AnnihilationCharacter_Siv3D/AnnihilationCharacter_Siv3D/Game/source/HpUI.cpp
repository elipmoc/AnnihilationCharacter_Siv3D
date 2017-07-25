#include "HpUI.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;
	HpUi::HpUi():m_hpFont(std::make_unique<FontObject>())
	{
		m_hpFont->SetPos({ 5, 0 });
	}
	void HpUi::Draw()const
	{
		m_hpFont->SetText(L"HP      :ŸŸŸŸ").SetColor(siv::Color(0,200,0)).Draw();
	}
}
