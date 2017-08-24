#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "define.hpp"

namespace game {
	//ファイルから地形データを読み込む
	class LoadFileTerrainData {
		std::vector<bool> terrainData[LANE_NUM];
	public:
		LoadFileTerrainData() {

		}
		void LoadFile() {
			std::ifstream ifs("terrain.txt");
			if(!ifs.is_open())
				throw siv::String(L"terrain.txt読み込みに失敗しました");
			std::string buf;
			for (size_t i = 0; i < LANE_NUM; i++) {
				if (!std::getline(ifs, buf))
					throw siv::String(L"行数が足りません");
				for (auto&& c : buf)
					terrainData[i].push_back(c);
			}
		}
	};
}