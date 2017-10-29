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


GameLoop::GameLoop(State * gameState, const String& name) 
	: gameState(gameState), name(name)
{ }


void GameLoop::Start()
{
	Location* l = gameState->GetCurrentLocation();

	while (!gameState->GetQuitState()) {

		printf("Welcome to %s.\n", name.c_str());
		//printf("Step: %i\n", i);

		l->Print();
		l->HandleInput();

		ClearSceen();

		l = gameState->GetCurrentLocation();
	}
}

void GameLoop::ClearSceen() const
{
	system("cls");
}