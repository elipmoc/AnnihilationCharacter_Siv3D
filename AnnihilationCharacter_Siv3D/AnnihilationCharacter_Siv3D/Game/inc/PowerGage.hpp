#pragma once

namespace game {

	//取得した力がどれくらいかを示すゲージのクラス
	class PowerGage {

	public:
		PowerGage(size_t maxPowerNum);
		void Draw(size_t powerNum);

	};

}