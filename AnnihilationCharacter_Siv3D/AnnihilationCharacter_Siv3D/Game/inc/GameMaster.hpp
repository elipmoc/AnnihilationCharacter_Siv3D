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
		//my�V�[��
		std::unique_ptr<MySceneManager> m_mySceneManager;
		//�n�`�f�[�^�ێ�
		std::unique_ptr<LoadFileTerrainData> m_loadFileTerrainData;
	public:
		const std::vector<bool>& GetTerrainData(size_t lane);
		static GameMaster& GetInstance() {
			return instance;
		};
		bool Init();
		void Start();
		void End();
	};

}