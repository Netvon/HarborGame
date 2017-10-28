#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "SmrtPtr.h"
#include "GameLoader.h"

#include "Vector.h"
#include "String.h"

#include <cstdio>
#include <iostream>


GameLoop::GameLoop()
{

	locations.push_back(new HarborLocation());
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



	HarborLocation* l = dynamic_cast<HarborLocation*>(locations.get(0));

	int i = 0;

	while (!State::Instance().GetQuitState()) {

		printf("Welcome to Harbor Game.\n");
		//printf("Step: %i\n", i);
		
		i++;

		l->Print();
		l->HandleInput();

		ClearSceen();
	}
}

void GameLoop::ClearSceen() const
{
	//system("cls");
}