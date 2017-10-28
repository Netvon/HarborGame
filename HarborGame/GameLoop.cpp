#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "SmrtPtr.h"
#include "GameLoader.h"
#include "SeaLocation.h"

#include "Vector.h"
#include "String.h"

#include <cstdio>
#include <iostream>


GameLoop::GameLoop()
{

	locations.push_back(new HarborLocation());
	locations.push_back(new SeaLocation());
}

GameLoop::~GameLoop()
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		delete locations.get(i);
	}
}

void GameLoop::Start()
{
	GameLoader gameLoader;

	// Loading all the components
	ships = gameLoader.LoadShips();
	harbors = gameLoader.LoadLocations();

	// locations = gameLoader.LoadLocations();

	HarborLocation* l = dynamic_cast<HarborLocation*>(locations[0]);
	Harbor& ref = harbors[0];

	l->SetCurrentHarbor(ref);

	while (!State::Instance().GetQuitState()) {

		printf("Welcome to Harbor Game.\n");
		//printf("Step: %i\n", i);

		l->Print();
		l->HandleInput();

		ClearSceen();
	}
}

void GameLoop::ClearSceen() const
{
	//system("cls");
}