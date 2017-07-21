#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl():m_terrainFont(TERRAIN_SIZE)
	{
		m_activeTerrains[0].resize(siv::Window::Size().x / TERRAIN_SIZE+2, false);
		m_activeTerrains[1].resize(siv::Window::Size().x / TERRAIN_SIZE+2, false);
		m_activeTerrains[2].resize(siv::Window::Size().x / TERRAIN_SIZE+2, false);
	}
	void TerrainControl::Update()
	{
		m_offset += 2;
		if (m_offset >= TERRAIN_SIZE)
			m_offset = 0;
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			m_terrainFont(L" ").draw(i*TERRAIN_SIZE-m_offset, 435);
		}
	}
}
