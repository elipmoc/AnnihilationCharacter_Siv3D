#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl():m_terrainFont(TERRAIN_SIZE),circle(3)
	{

		for (auto & item : m_activeTerrains)
			item.resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
	}

	//���̒n�`���Z�b�g����
	void TerrainControl::NextTerrainLoad() {
		m_offset = 0;

		for (auto & item : m_activeTerrains) {
			//�擪�̃f�[�^����폜
			item.pop_front();
			//�Ō���ɐV�����n�`�f�[�^���Z�b�g����
			item.push_back(siv::Random(0,1));
		}
	}

	void TerrainControl::Update()
	{
		m_offset += 2;
		if (m_offset >= TERRAIN_SIZE)
			NextTerrainLoad();
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			for (size_t j = 0; j < LANE_NUM; j++) {
				if (m_activeTerrains[j][i]) {
					m_terrainFont(L"��").draw(i*TERRAIN_SIZE - m_offset, GetTerrainY(j)-FIX_TERRAIN_Y);
					//�n�`�̍��W�f�o�b�O�p
					circle.setPos({ i*TERRAIN_SIZE - m_offset, GetTerrainY(j)}).draw(siv::Palette::Red);
				}
			}
		}
	}


}
