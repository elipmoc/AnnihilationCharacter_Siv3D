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
			throw siv::String(fileName+L"でエラーが発生しました");
		}
	}
	void GamePadConfigLoader::Save(const GamePadData & gpd,const siv::String& fileName)
	{
		try {
			siv::TextWriter writer(fileName);
			writer.write(L"{");
			writer.write(L"\"jump\":");
			writer.write(gpd.jump);
			writer.write(L",\"barrier\":");
			writer.write(gpd.barrier);
			writer.write(L",\"fuwari\":");
			writer.write(gpd.fuwari);
			writer.write(L"}");
		}
		catch (...) {
			throw siv::String(fileName + L"でエラーが発生しました");
		}
	}
}