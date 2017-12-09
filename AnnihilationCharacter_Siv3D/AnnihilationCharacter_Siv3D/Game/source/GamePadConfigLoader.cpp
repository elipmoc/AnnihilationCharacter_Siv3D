#include "GamePadConfigLoader.hpp"

namespace game {
	GamePadData GamePadConfigLoader::Load(siv::String fileName)
	{
		try {
			GamePadData gpd;
			auto json=siv::JSONReader(fileName);
			gpd.barrier = json[L"barrier"].getNumber();
			gpd.jump = json[L"jump"].getNumber();
			gpd.fuwari = json[L"fuwari"].getNumber();
			return gpd;
		}
		catch (...) {
			throw siv::String(fileName+L"Ç≈ÉGÉâÅ[Ç™î≠ê∂ÇµÇ‹ÇµÇΩ");
		}
	}
}