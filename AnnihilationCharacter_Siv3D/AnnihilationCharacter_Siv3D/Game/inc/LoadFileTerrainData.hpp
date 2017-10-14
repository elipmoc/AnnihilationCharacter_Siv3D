#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include "define.hpp"
#include "TerrainData.hpp"

namespace game {
	//ファイルから地形データを読み込む関数
	 std::unique_ptr<TerrainData> LoadFileTerrainData(const std::string& fileName) {
		std::array<std::vector<bool>, 3> data;
		std::ifstream ifs(fileName);
		if (!ifs.is_open())
			throw siv::String(L"terrain.txt読み込みに失敗しました");
		std::string buf;
		for (int i = LANE_NUM-1; i >=0; i--) {
			if (!std::getline(ifs, buf))
				throw siv::String(L"terrain.txt行数が足りません");
			for (auto&& c : buf) {
				if (c == '0' || c == '1')
					data[i].push_back(c == '0' ? false : true);
				else
					throw siv::String(L"terrain.txt不正な文字があります");
			}
		}
		return std::make_unique<TerrainData>(std::move(data));
	}
}