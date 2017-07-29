#pragma once
#include <memory>

namespace elipmocframework {
	class FontObject;
}

namespace game {
	class HpUi {
		size_t m_hp=10;
		std::unique_ptr<elipmocframework::FontObject> m_hpFont;
	public:
		HpUi();
		size_t GetHp()const noexcept{ return m_hp; }
		void SetHp(size_t hp) noexcept{ m_hp=hp; }
		void Draw()const;
	};
}