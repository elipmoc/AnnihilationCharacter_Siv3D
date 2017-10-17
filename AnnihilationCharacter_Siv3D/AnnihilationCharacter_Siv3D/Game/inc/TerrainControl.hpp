#pragma once
#include <deque>
#include "define.hpp"

namespace game {

	class TerrainData;

	//地形配列を制御するクラス
	class TerrainControl {
	public:

		//地形データ
		const TerrainData* m_terrainData;

		//地形一つのサイズ
		static constexpr size_t TERRAIN_SIZE = 40;

		//地形データを切り替え
		void SetTerrainData(const TerrainData& terrainData) {
			index=0;
			finishedFlag = false;
			m_terrainData = &terrainData;
		}

		//特定のレーンの地形の高さを得る
		double GetTerrainY(size_t lane)const {
			if (lane >= LANE_NUM)throw siv::String(L"無効なレーン番号です");
			return 450 - lane * 150;
		}

		//あるX座標のあるレーンに地形があるかどうか
		bool IsExistTerrainFromX(double x, size_t lane) const{
			return m_activeTerrains[lane][(int)(x+m_offset) / TERRAIN_SIZE];
		}

		//param: 始める位置
		TerrainControl(const TerrainData& terrainData,const size_t startPos=0);
		//エリアの末端まで行ったかどうか
		bool IsFinished() { return finishedFlag; }
		void Update();
	private:
		//地形のインデックス
		size_t index = 0;

		//エリア終了フラグ
		bool finishedFlag = false;

		//現在画面に表示されている地形
		std::deque<bool> m_activeTerrains[LANE_NUM];

		//表示用の地形文字
		const siv::Font m_terrainFont;

		//デバック用
		siv::Circle circle;

		//文字の高さ補正用（文字は表示位置がずれるため、ギャップを埋めなけらばならぬ）
		static constexpr size_t FIX_TERRAIN_Y=19;

		//地形の座標をずらす
		double m_offset = 0;

		void NextTerrainLoad();

	};
}