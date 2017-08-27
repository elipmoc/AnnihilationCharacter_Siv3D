#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "define.hpp"

namespace game {
	//ファイルから地形データを読み込むクラス
	class LoadFileTerrainData {
		std::vector<bool> m_terrainData[LANE_NUM];
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
					throw siv::String(L"terrain.txt行数が足りません");
				for (auto&& c : buf) {
					if (c == '0' || c == '1')
						m_terrainData[i].push_back(c == '0' ? false : true);
					else
						throw siv::String(L"terrain.txt不正な文字があります");
				}
			}
		}

		const std::vector<bool>& GetTerrainData(size_t lane) const noexcept{
			return m_terrainData[LANE_NUM-lane-1];
		}
	};
}