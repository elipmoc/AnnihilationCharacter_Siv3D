#pragma once

namespace game {

	//ファイルから敵生成データを読み込むクラス
	class LoadFileConfig {
		size_t m_startTime;
		bool m_showTimeFlag;
	public:
		void LoadFile() {
			try {
				siv::JSONReader json(L"config.json");
				m_startTime = json[L"StartTime"].getNumber();
				m_showTimeFlag = json[L"ShowTime"].getBool();
			}
			catch (...) {
				throw siv::String(L"config.jsonでエラーが発生しました");
			}
		}

		size_t GetStartTime()const noexcept {
			return m_startTime;
		}
		bool GetShowTimeFlag() const noexcept{ return m_showTimeFlag; }

	};
}