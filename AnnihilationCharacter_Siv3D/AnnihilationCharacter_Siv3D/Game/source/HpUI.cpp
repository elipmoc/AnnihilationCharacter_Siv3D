#include "HpUI.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;
	HpUi::HpUi():m_hpFont(std::make_unique<FontObject>())
	{
		m_hpFont->SetPos({ 5, 0 });
	}
	void HpUi::Draw(const size_t hp)const
	{
		static siv::String str;
		str = L"HP      :";
		for (size_t i = 0; i < hp; i++)
			str += L"Ÿ";
		m_hpFont->SetText(str).SetColor(siv::Color(0,200,0)).Draw();
	}
}
