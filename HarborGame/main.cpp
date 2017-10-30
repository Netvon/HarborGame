// HarborGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"
#include "State.h"
#include "HarborLocation.h"
#include "ShopLocation.h"
#include "LeaveLocation.h"
#include "SeaLocation.h"
#include "BattleLocation.h"

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

		gameState->GetPlayer().AddGold(50000);

		gameState->AddLocation<HarborLocation>("harbor");
		gameState->AddLocation<ShopLocation>("shop");
		gameState->AddLocation<LeaveLocation>("leave");
		gameState->AddLocation<SeaLocation>("sea");
		gameState->AddLocation<BattleLocation>("battle");
		gameState->NavigateToLocation("harbor", gameState->GetHarbor(5)->GetName());
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

		printf("An unknown error was encountered, please restart the game.\n");
		system("pause");
	}

	return _CrtDumpMemoryLeaks();
}

