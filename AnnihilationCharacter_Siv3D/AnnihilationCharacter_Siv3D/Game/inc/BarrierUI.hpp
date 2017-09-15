#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class BarrierUi {
		std::unique_ptr<elipmocframework::FontObject> m_barrierFont;
	public:
		BarrierUi();
		void Draw(const size_t)const;
	};
}