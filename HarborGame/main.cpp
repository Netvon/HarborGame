// HarborGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"

int main()
{
	GameLoop* gameloop = nullptr;

	try {
		gameloop = new GameLoop();
		gameloop->Start();

		delete gameloop;
	}
	catch (...) {
		if (gameloop != nullptr)
			delete gameloop;

		throw;
	}

	return _CrtDumpMemoryLeaks();
}

