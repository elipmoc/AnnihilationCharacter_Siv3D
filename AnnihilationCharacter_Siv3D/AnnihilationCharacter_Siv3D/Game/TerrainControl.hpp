#pragma once
#include <vector>
#include <queue>
namespace game {
	//地形配列を制御するクラス
	class TerrainControl {
		//地形一つのサイズ
		static constexpr size_t TERRAIN_SIZE= 30;
		//レーン数
		static constexpr size_t LANE_NUM=3;
		//地形情報のリスト
		std::vector<bool>m_terrainFlags[LANE_NUM];
		//現在画面に表示されている地形
		std::vector<bool> m_activeTerrains[LANE_NUM];
		//表示用の地形文字
		const siv::Font m_terrainFont;
		//地形をずらす
		double m_offset = 0;
	public:
		TerrainControl();
		void Update();
	};
}