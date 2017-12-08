#pragma once
namespace game {

	struct GamePadData {
		uint32 right;
		uint32 left;
		uint32 up;
		uint32 down;
		uint32 jump;
		uint32 barrier;
		uint32 fuwari;
	};

	class GamePadInput {

		bool loadGamePadData = false;
		GamePadInput();
		~GamePadInput();

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