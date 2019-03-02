#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include "SceneBase.hpp"

namespace game {

	class TerrainData;
	class LoadFileEnemyInfo;
	class LoadFileConfig;
	struct EnemyInfo;
	class GameMaster {
		GameMaster();
		~GameMaster();
		static GameMaster instance;
		//�V�[���Ǘ��N���X�̕ێ�
		std::unique_ptr<MySceneManager> m_mySceneManager;
		//�n�`�f�[�^�ێ�
		std::unordered_map<std::string,std::unique_ptr<TerrainData>> m_terrainDataMap;
		//�G�f�[�^�ێ�
		std::unique_ptr<LoadFileEnemyInfo> m_loadFileEnemyInfo;
		//config�f�[�^�ێ�
		std::unique_ptr<LoadFileConfig> m_loadFileConfig;
	public:
		const TerrainData& GetTerrainData(const std::string& terrainName)const;
		const std::vector<std::unique_ptr<EnemyInfo>>& GetEnemyInfoList()const noexcept;
		const size_t GetStartTime()const noexcept;
		const bool GetShowTimeFlag()const noexcept;
		static GameMaster& GetInstance() {
			return instance;
		};
		bool Init();
		void Start();
		void End();
	};

}