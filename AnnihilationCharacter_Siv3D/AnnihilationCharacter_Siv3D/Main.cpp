#include "GameMaster.hpp"




void Main()
{
	game::GameMaster::GetInstance().Init();
	game::GameMaster::GetInstance().Start();

}
