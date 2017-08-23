#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl() :m_terrainFont(TERRAIN_SIZE), circle(3)
	{
		m_terrainFlags[0] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
		m_terrainFlags[1] = { 1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1};
		m_terrainFlags[2] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		for (auto & item : m_activeTerrains)
			item.resize(siv::Window::Size().x / TERRAIN_SIZE + 2, true);
	}

	//次の地形をセットする
	void TerrainControl::NextTerrainLoad() {
		static size_t index = 0;
		m_offset = 0;

		/*for (auto & item : m_activeTerrains) {
			//先頭のデータを一つ削除
			item.pop_front();
			//最後尾に新しい地形データをセットする
			item.push_back(siv::Random(0,1));
		}*/
		for (size_t i = 0; i < LANE_NUM; i++) {
			//先頭のデータを一つ削除
			m_activeTerrains[i].pop_front();
			//最後尾に新しい地形データをセットする
			m_activeTerrains[i].push_back(m_terrainFlags[i][index]);
		}
		index = (index+1)%m_terrainFlags[0].size();
	}

	void TerrainControl::Update()
	{
		m_offset += 2;
		if (m_offset >= TERRAIN_SIZE)
			NextTerrainLoad();
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			for (size_t j = 0; j < LANE_NUM; j++) {
				if (m_activeTerrains[j][i]) {
					m_terrainFont(L"□").draw(i*TERRAIN_SIZE - m_offset, GetTerrainY(j)-FIX_TERRAIN_Y);
					//地形の座標デバッグ用
					circle.setPos({ i*TERRAIN_SIZE - m_offset, GetTerrainY(j)}).draw(siv::Palette::Red);
				}
			}
		}
	}


}
