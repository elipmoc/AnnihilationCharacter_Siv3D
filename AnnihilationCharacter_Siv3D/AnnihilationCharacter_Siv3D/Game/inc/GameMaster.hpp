#pragma once
#include <memory>
#include <vector>
#include "SceneBase.hpp"

namespace game {

	class LoadFileTerrainData;
	class GameMaster {
		GameMaster();
		~GameMaster();
		static GameMaster instance;
		//myシーン
		std::unique_ptr<MySceneManager> m_mySceneManager;
		//地形データ保持
		std::unique_ptr<LoadFileTerrainData> m_loadFileTerrainData;
	public:
		const std::vector<bool>& GetTerrainData(size_t lane);
		static GameMaster& GetInstance() {
			return instance;
		};
		void Init();
		void Start();
		void End();
	};

}