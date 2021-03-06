#include "TerrainControl.hpp"
#include "TerrainData.hpp"

namespace game {
	TerrainControl::TerrainControl(const TerrainData& terrainData,const size_t startPos) :
		m_terrainData(&terrainData),m_terrainFont(TERRAIN_SIZE), circle(3)
	{
		size_t offset = startPos * 4;
		index = offset / TERRAIN_SIZE;
		m_offset = offset - index*TERRAIN_SIZE;
		for (size_t lane = 0; lane < LANE_NUM; lane++)
			for (size_t i = 0; i < siv::Window::Size().x / TERRAIN_SIZE + 2; i++)
				m_activeTerrains[lane].push_back((*m_terrainData)(lane)[index+i]);
		index += siv::Window::Size().x / TERRAIN_SIZE + 2;
	}

	//次の地形をセットする
	void TerrainControl::NextTerrainLoad() {
		m_offset = 0;
		for (size_t i = 0; i < LANE_NUM; i++) {
			//先頭のデータを一つ削除
			m_activeTerrains[i].pop_front();
			//最後尾に新しい地形データをセットする
			m_activeTerrains[i].push_back((*m_terrainData)(i)[index]);
		}
		index++;
		if (index == (*m_terrainData)(0).size()) {
			finishedFlag = true;
			index = 0;
		}
	}

	void TerrainControl::Update()
	{
		m_offset += 4;
		if (m_offset >= TERRAIN_SIZE)
			NextTerrainLoad();
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			for (size_t j = 0; j < LANE_NUM; j++) {
				if (m_activeTerrains[j][i]) {
					m_terrainFont(L"□").draw(i*TERRAIN_SIZE - m_offset, GetTerrainY(j) - FIX_TERRAIN_Y, siv::Color{255,255,255,100});
					//地形の座標デバッグ用
					//circle.setPos({ i*TERRAIN_SIZE - m_offset, GetTerrainY(j)}).draw(siv::Palette::Red);
				}
			}
		}
	}


}
