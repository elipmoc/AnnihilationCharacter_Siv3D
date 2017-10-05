#pragma once

namespace game {

	//ファイルから敵生成データを読み込むクラス
	class LoadFileConfig {
		size_t m_startTime;
	public:
		void LoadFile() {
			try {
				siv::JSONReader json(L"config.json");
				m_startTime = json[L"StartTime"].getNumber();
			}
			catch (...) {
				throw siv::String(L"config.jsonでエラーが発生しました");
			}
		}

		const int GetStartTime()const noexcept {
			return m_startTime;
		}
	};
}