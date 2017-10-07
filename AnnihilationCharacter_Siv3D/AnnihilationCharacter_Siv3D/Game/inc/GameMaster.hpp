#pragma once
#include <memory>
#include <vector>
#include "SceneBase.hpp"

namespace game {

	class LoadFileTerrainData;
	class LoadFileEnemyInfo;
	class LoadFileConfig;
	struct EnemyInfo;
	class GameMaster {
		GameMaster();
		~GameMaster();
		static GameMaster instance;
		//my�V�[��
		std::unique_ptr<MySceneManager> m_mySceneManager;
		//�n�`�f�[�^�ێ�
		std::unique_ptr<LoadFileTerrainData> m_loadFileTerrainData;
		//�G�f�[�^�ێ�
		std::unique_ptr<LoadFileEnemyInfo> m_loadFileEnemyInfo;
		//config�f�[�^�ێ�
		std::unique_ptr<LoadFileConfig> m_loadFileConfig;
	public:
		const std::vector<bool>& GetTerrainData(size_t lane)const noexcept;
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