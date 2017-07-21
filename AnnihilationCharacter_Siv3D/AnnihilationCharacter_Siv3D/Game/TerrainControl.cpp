#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl():m_terrainFont(TERRAIN_SIZE)
	{
		m_activeTerrains[0].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
		m_activeTerrains[1].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
		m_activeTerrains[2].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
	}

	//次の地形をセットする
	void TerrainControl::NextTerrainLoad() {
		m_offset = 0;

		//先頭のデータを一つ削除
		m_activeTerrains[0].pop_front();
		//最後尾に新しい地形データをセットする
		m_activeTerrains[0].push_back( false);
	}

	void TerrainControl::Update()
	{
		m_offset += 2;
		if (m_offset >= TERRAIN_SIZE)
			NextTerrainLoad();
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			if(m_activeTerrains[0][i])
				m_terrainFont(L"□").draw(i*TERRAIN_SIZE-m_offset, 425);
		}
	}


}
