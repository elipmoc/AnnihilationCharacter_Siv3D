#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl():m_terrainFont(TERRAIN_SIZE),circle(3)
	{

		for (auto & item : m_activeTerrains)
			item.resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
	}

	//次の地形をセットする
	void TerrainControl::NextTerrainLoad() {
		m_offset = 0;

		for (auto & item : m_activeTerrains) {
			//先頭のデータを一つ削除
			item.pop_front();
			//最後尾に新しい地形データをセットする
			item.push_back(true);
		}
	}


	//特定のレーンの地形の高さを得る
	double TerrainControl::GetTerrainY(size_t lane)const{
		if (lane >= LANE_NUM)throw siv::String(L"無効なレーン番号です");
		return 425 - lane * 150;
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
