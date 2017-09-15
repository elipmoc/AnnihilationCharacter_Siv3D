#include "BarrierUI.hpp"
#include "FontObject.hpp"

namespace game {

	using elipmocframework::FontObject;
	BarrierUi::BarrierUi():m_barrierFont(std::make_unique<FontObject>())
	{
		m_barrierFont->SetPos({ 0,40 });
	}
	void BarrierUi::Draw(const size_t barrierCount)const
	{
		static siv::String str;
		str = L"ƒoƒŠƒA:";
		for (size_t i = 0; i < barrierCount; i++)
			str += L"Ÿ";
		m_barrierFont->SetText(str).SetColor(siv::Color(0, 100, 255)).Draw();
	}
}
