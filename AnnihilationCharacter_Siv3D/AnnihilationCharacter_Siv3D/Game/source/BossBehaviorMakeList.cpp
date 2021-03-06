#include "BossBehaviorMakeList.hpp"
#include "BossBehaviorMake.hpp"
#include "BossBehavior01.hpp"
#include "BossBehavior02.hpp"
#include "BossBehaviorWait.hpp"
#include "BulletListCreator.hpp"
#include "ParticleList.hpp"

namespace game {
	BossBehaviorMakeList::BossBehaviorMakeList()
		:list
	{
		std::make_unique<BossBehaviorMake<BossBehavior01>>(),
		std::make_unique<BossBehaviorMake<BossBehavior02>>(),
		std::make_unique<BossBehaviorMake<BossBehaviorWait>>()
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