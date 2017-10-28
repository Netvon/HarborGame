// HarborGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"
#include "State.h"
#include "HarborLocation.h"

int main()
{
	State* gameState = nullptr;
	GameLoop* gameloop = nullptr;
	try {
		gameState = new State();
		gameState->LoadShipAssets("Files/schepen.csv");
		gameState->LoadHarborAssets(
			"Files/goederen prijzen.csv",
			"Files/goederen hoeveelheid.csv",
			"Files/afstanden tussen steden.csv"
		);

		gameState->AddLocation<HarborLocation>("harbor");
		gameState->NavigateToLocation("harbor", gameState->GetHarbor(0)->GetName());
		//Location* current = gameState->GetCurrentLocation();
	
		gameloop = new GameLoop(gameState, "Harbor Game");
		gameloop->Start();

		delete gameloop;
		delete gameState;
	}
	catch (...) {
		if (gameloop != nullptr)
			delete gameloop;

		if (gameloop != nullptr)
			delete gameState;

		throw;
	}

	return _CrtDumpMemoryLeaks();
}

