#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class HpUi {
		std::unique_ptr<elipmocframework::FontObject> m_hpFont;
	public:
		HpUi();
		void Draw(const size_t hp)const;
	};
}