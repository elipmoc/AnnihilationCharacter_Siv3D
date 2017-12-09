#pragma once
namespace game {

	struct GamePadData {
	public:
		unsigned int jump;
		unsigned int barrier;
		unsigned int fuwari;
	};

	class GamePadConfigLoader {
	public:
		GamePadConfigLoader() {};
		GamePadData Load(siv::String fileName);
	};
}