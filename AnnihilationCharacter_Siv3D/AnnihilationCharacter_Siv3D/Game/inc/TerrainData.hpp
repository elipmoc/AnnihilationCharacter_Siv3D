#pragma once
#include "define.hpp"
#include <vector>
#include <array>

namespace game {

	class TerrainData {
		const std::array<std::vector<bool>, LANE_NUM> m_data;
	public:

		TerrainData(std::array < std::vector<bool>,LANE_NUM>&& data):
			m_data(std::move(data))
		{}

		const std::vector<bool>& operator()(size_t lane) const{
			return m_data[lane];
		}
	};

}