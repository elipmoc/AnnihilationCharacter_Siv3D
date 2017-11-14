#include "PowerSpawn.hpp"
#include "Power.hpp"

namespace game {

	PowerSpawn::PowerSpawn()
	{

	}

	PowerSpawn::~PowerSpawn() = default;

	void PowerSpawn::Draw() const
	{
		for (auto& item : m_powerList) {
			item->DrawCenter();
		}
	}

	void PowerSpawn::Update()
	{
		if (count % 30 == 0) {
			m_powerList.emplace_back(
				std::make_unique<Power>(siv::Vec2{siv::Window::Width()+10,siv::Random()*siv::Window::Height()}, siv::Vec2{ -4,0 }));
		}
		count++;
		auto itr=std::remove_if(
			m_powerList.begin(),m_powerList.end(), [](const std::unique_ptr<Power>& power) {
			return power->IsEnableDelete();
		});

		m_powerList.erase(itr, m_powerList.end());
		
		for (auto& item : m_powerList) {
			item->Update();
		}
	}
}