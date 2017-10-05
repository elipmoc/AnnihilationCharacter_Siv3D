#pragma once

namespace game {

	//�t�@�C������G�����f�[�^��ǂݍ��ރN���X
	class LoadFileConfig {
		size_t m_startTime;
	public:
		void LoadFile() {
			try {
				siv::JSONReader json(L"config.json");
				m_startTime = json[L"StartTime"].getNumber();
			}
			catch (...) {
				throw siv::String(L"config.json�ŃG���[���������܂���");
			}
		}

		const int GetStartTime()const noexcept {
			return m_startTime;
		}
	};
}