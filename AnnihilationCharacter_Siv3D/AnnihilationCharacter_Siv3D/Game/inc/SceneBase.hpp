#pragma once

namespace game {

	//難易度
	enum class Level {
		Normal=0,
		Rengoku=1
	};
	//シーン間で共有するデータ
	struct ShareGameData { siv::String player; Level level; };
	//シーン操作クラス
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//シーンの基底クラス
	using MySceneBase = MySceneManager::Scene;
}