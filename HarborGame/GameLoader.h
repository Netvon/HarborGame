#include "Ship.h"
#include "Harbor.h"

#pragma once
class GameLoader
{
public:
	GameLoader();
	~GameLoader();

	Vector<Ship> LoadShips();
	Vector<Harbor> LoadLocations();

private:
	

};