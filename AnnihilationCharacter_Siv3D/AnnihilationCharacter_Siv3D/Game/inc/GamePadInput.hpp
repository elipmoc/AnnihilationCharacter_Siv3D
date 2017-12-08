#pragma once
#include "GamePadConfigLoader.hpp"

namespace game {



	class GamePadInput {

		bool loadGamePadData = false;
		GamePadInput() {};
		~GamePadInput() {};

		static GamePadInput instance;

	public:

		void LoadGamePadData(GamePadData);

		static GamePadInput & GetInstance() { return instance; }

		siv::Key GetRight()const noexcept;
		siv::Key GetLeft()const noexcept;
		siv::Key GetUp()const noexcept;
		siv::Key GetDown()const noexcept;
		siv::Key GetJump()const noexcept;
		siv::Key GetBarrier()const noexcept;
		siv::Key GetFuwari()const noexcept;
	};
}