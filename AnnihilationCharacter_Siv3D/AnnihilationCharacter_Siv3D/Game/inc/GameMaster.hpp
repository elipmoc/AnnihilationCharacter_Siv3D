#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {

	class GameMaster {
		GameMaster();
		~GameMaster();
		static GameMaster instance;
		//my�V�[��
		std::unique_ptr<MySceneManager> mySceneManager;
	public:
		static GameMaster& GetInstance() {
			return instance;
		};
		void Init();
		void Start();
		void End();
	};

}