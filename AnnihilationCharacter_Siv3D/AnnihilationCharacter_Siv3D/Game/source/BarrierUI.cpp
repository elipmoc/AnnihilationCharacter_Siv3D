#include "BarrierUI.hpp"
#include "FontObject.hpp"

namespace game {

	using elipmocframework::FontObject;
	BarrierUi::BarrierUi():m_barrierFont(std::make_unique<FontObject>())
	{
		m_barrierFont->SetPos({ 0,40 });
	}
	void BarrierUi::Draw()const
	{
		m_barrierFont->SetText(L"�o���A:������").SetColor(siv::Color(0, 100, 255)).Draw();
	}
}
