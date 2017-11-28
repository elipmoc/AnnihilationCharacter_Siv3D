#include "BossBehaviorMakeList.hpp"
#include "BossBehaviorMake.hpp"
#include "BossBehavior01.hpp"
#include "BulletListCreator.hpp"

namespace game {
	BossBehaviorMakeList::BossBehaviorMakeList()
		:list
	{
		std::make_unique<BossBehaviorMake<BossBehavior01>>(),
		nullptr
	}
	{
		
	}
	BossBehaviorMakeList::~BossBehaviorMakeList() = default;

	std::unique_ptr<BossBehaviorMakeBase> BossBehaviorMakeList::Next()
	{
		index++;
		return std::move(list[index - 1]);
	}
}