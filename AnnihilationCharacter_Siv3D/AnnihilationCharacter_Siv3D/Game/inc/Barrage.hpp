#pragma once
#include <memory>

namespace elipmocframework {
	template<class Object>
	class ObjectPool;
}

namespace game {
	class 
	class Barrage {
		std::unique_ptr<elipmocframework::ObjectPool<int>> m_bulletPool;
	};
}