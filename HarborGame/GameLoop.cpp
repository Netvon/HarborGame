#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "GameLoader.h"
#include "SeaLocation.h"

#include "Vector.h"
#include "String.h"

#include <cstdio>
#include <iostream>


GameLoop::GameLoop(State * gameState, const String& name) 
	: gameState(gameState), name(name)
{ }


void GameLoop::Start() const
{
	int won = -1;

	Location* l = gameState->GetCurrentLocation();

	while (!gameState->GetQuitState()) {

		printf("Welcome to %s.\n", name.c_str());
		//printf("Step: %i\n", i);

		l->Print();
		l->HandleInput();

		ClearSceen();

		auto& ship = gameState->GetPlayer().GetShip();
		if (ship != nullptr && ship.GetCurrentHealth() == 0) {
			won = 0;
			break;
		}
		
		if (gameState->GetPlayer().GetGold() >= 1000000) {
			won = 1;
			break;
		}

		l = gameState->GetCurrentLocation();
	}

	if (won == 1) {
		printf("| You have obtained 1.000.000 gold.\n\n");
		printf("| We had an interesting journey Captain, we came from nothing ...\n");
		printf("| Look at us now, we shall live like kings.\n| Enjoy your retirement!\n");
		system("pause");
	}
	else if (won == 0) {
		printf("| Our ship was lost at sea.\n\n");
		printf("| It was an honour serving with you captain. But I am afraid our journey ends here.\n");
		printf("| ... ...\n| Farewell.\n");
		system("pause");
	}
}

void GameLoop::ClearSceen() const
{
	system("cls");
}