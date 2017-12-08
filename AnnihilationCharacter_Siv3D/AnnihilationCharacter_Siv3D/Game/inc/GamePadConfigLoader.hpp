#pragma once
namespace game {

	struct GamePadData {
	public:
		unsigned int right;
		unsigned int left;
		unsigned int up;
		unsigned int down;
		unsigned int jump;
		unsigned int barrier;
		unsigned int fuwari;
	};

	class GamePadConfigLoader {
	public:
		GamePadConfigLoader();
		template<class F>
		void Load(std::string fileName,F f);
	};
}