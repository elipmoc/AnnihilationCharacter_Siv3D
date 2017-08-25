#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "define.hpp"

namespace game {
	//�t�@�C������n�`�f�[�^��ǂݍ���
	class LoadFileTerrainData {
		std::vector<bool> terrainData[LANE_NUM];
	public:
		LoadFileTerrainData() {

		}
		void LoadFile() {
			std::ifstream ifs("terrain.txt");
			if(!ifs.is_open())
				throw siv::String(L"terrain.txt�ǂݍ��݂Ɏ��s���܂���");
			std::string buf;
			for (size_t i = 0; i < LANE_NUM; i++) {
				if (!std::getline(ifs, buf))
					throw siv::String(L"terrain.txt�s��������܂���");
				for (auto&& c : buf) {
					if (c == '0' || c == '1')
						terrainData[i].push_back(c == '0' ? false : true);
					else
						throw siv::String(L"terrain.txt�s���ȕ���������܂�");
				}
			}
		}

		const std::vector<bool>& GetTerrainData(size_t lane) {
			return terrainData[LANE_NUM-lane-1];
		}
	};
}