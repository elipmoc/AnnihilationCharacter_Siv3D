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
		for (auto& item : *m_powerList) {
			item.DrawCenter();
		}
	}

	void PowerSpawn::Update()
	{
		if (count % 30 == 0) {
			m_powerList->emplace_back(Power({siv::Window::Width()+10,siv::Random()*siv::Window::Height()}, { -1,0 }));
		}
		count++;
		for (auto& item : *m_powerList) {
			item.Update();
		}
	}
}