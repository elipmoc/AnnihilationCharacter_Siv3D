#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class BarrierUi {
		//バリアできる回数
		size_t m_barrierCount = 3;
		std::unique_ptr<elipmocframework::FontObject> m_barrierFont;
	public:
		BarrierUi();
		size_t GetBarrierCount()const { return m_barrierCount; }
		void Draw()const;
	};
}