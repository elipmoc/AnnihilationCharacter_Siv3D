#pragma once

namespace game {
	//シーン間で共有するデータ
	struct ShareGameData { siv::String player; };
	//シーン操作クラス
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//シーンの基底クラス
	using MySceneBase = MySceneManager::Scene;
}