#include "PowerSpawn.hpp"
#include "Power.hpp"

namespace game {



	PowerSpawn::PowerSpawn()
		:m_powerList(std::make_unique<std::vector<Power>>())
	{

	}

	PowerSpawn::~PowerSpawn() = default;

	void PowerSpawn::Draw() const
	{
	}

	void PowerSpawn::Update()
	{
	}
}