#pragma once

namespace game {

	//��Փx
	enum class Level {
		yawaraka=0,
		Normal=1,
		Rengoku=2
	};
	//�V�[���Ԃŋ��L����f�[�^
	struct ShareGameData { siv::String player; Level level; };
	//�V�[������N���X
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//�V�[���̊��N���X
	using MySceneBase = MySceneManager::Scene;
}