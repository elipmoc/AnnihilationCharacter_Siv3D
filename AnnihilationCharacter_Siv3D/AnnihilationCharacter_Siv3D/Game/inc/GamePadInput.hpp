#pragma once
#include "GamePadConfigLoader.hpp"

namespace game {



	class GamePadInput {
		GamePadData gamePadData{0,1,5};
		GamePadInput() {};
		~GamePadInput() {};
		int right = 0;
		int left = 0;
		int up = 0;
		int down = 0;

		static GamePadInput instance;

	public:

		void LoadGamePadData(GamePadData gamePadData) {
		}

		void Update() {
			if (siv::Gamepad(0).x > 0.5)
				right++;
			else right = 0;

			if (siv::Gamepad(0).x < -0.5)
				left++;
			else left = 0;

			if (siv::Gamepad(0).y> 0.5)
				down++;
			else down = 0;

			if (siv::Gamepad(0).y < -0.5)
				up++;
			else up = 0;

		}

		static GamePadInput & GetInstance() { return instance; }

		int GetRight()const noexcept {
			return right;
		}
		int GetLeft()const noexcept {
			return left;
		}
		int GetUp()const noexcept {
			return up;
		}
		int GetDown()const noexcept {
			return down;
		}
		siv::Key GetJump()const noexcept {
			return siv::Gamepad(0).button(gamePadData.jump);
		}
		siv::Key GetBarrier()const noexcept {
			return siv::Gamepad(0).button(gamePadData.barrier);
		}
		siv::Key GetFuwari()const noexcept {
			return siv::Gamepad(0).button(gamePadData.fuwari);
		}
	};
}