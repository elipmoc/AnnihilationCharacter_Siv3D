#include "GameMaster.hpp"




void Main()
{
	if(game::GameMaster::GetInstance().Init()==false)return;
	game::GameMaster::GetInstance().Start();
}
