#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include "define.hpp"
#include "TerrainData.hpp"

namespace game {
	//�t�@�C������n�`�f�[�^��ǂݍ��ފ֐�
	 std::unique_ptr<TerrainData> LoadFileTerrainData(const std::string& fileName) {
		std::array<std::vector<bool>, 3> data;
		std::ifstream ifs(fileName);
		if (!ifs.is_open())
			throw siv::String(L"terrain.txt�ǂݍ��݂Ɏ��s���܂���");
		std::string buf;
		for (int i = LANE_NUM-1; i >=0; i--) {
			if (!std::getline(ifs, buf))
				throw siv::String(L"terrain.txt�s��������܂���");
			for (auto&& c : buf) {
				if (c == '0' || c == '1')
					data[i].push_back(c == '0' ? false : true);
				else
					throw siv::String(L"terrain.txt�s���ȕ���������܂�");
			}
		}
		return std::make_unique<TerrainData>(std::move(data));
	}
}