#include "BarrierUI.hpp"
#include "FontObject.hpp"

namespace game {

	using elipmocframework::FontObject;
	BarrierUi::BarrierUi():m_barrierFont(std::make_unique<FontObject>())
	{
		m_barrierFont->SetPos({ 0,40 });
	}
	void BarrierUi::Draw()
	{
		m_barrierFont->SetText(L"ƒoƒŠƒA:ŸŸŸ").SetColor(siv::Color(0, 100, 255)).Draw();
	}
}
