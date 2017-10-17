// HarborGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"


int main()
{
	GameLoop gameloop;
	gameloop.Start();

	return _CrtDumpMemoryLeaks();
}

