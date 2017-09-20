#include "TerrainControl.hpp"
#include "GameMaster.hpp"

namespace game {
	TerrainControl::TerrainControl() :m_terrainFont(TERRAIN_SIZE), circle(3)
	{
		for (size_t lane = 0; lane < LANE_NUM; lane++)
			for (size_t i = 0; i < siv::Window::Size().x / TERRAIN_SIZE + 2; i++)
				m_activeTerrains[lane].push_back(GameMaster::GetInstance().GetTerrainData(lane)[i]);
	}

	//���̒n�`���Z�b�g����
	void TerrainControl::NextTerrainLoad() {
		static size_t index = 0;
		m_offset = 0;
		for (size_t i = 0; i < LANE_NUM; i++) {
			//�擪�̃f�[�^����폜
			m_activeTerrains[i].pop_front();
			//�Ō���ɐV�����n�`�f�[�^���Z�b�g����
			m_activeTerrains[i].push_back(GameMaster::GetInstance().GetTerrainData(i)[index]);
		}
		index++;
		if (index == GameMaster::GetInstance().GetTerrainData(0).size())
			finishedFlag = true;
	}

	void TerrainControl::Update()
	{
		m_offset += 4;
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
