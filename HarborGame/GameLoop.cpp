#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"

#include <cstdio>
#include <iostream>

using namespace std;

GameLoop::GameLoop()
{
	
}

GameLoop::~GameLoop()
{
	
}

void GameLoop::Start()
{
	auto state = State::Instance();
	HarborLocation l;

	int i = 0;

	while (!state->GetQuitState()) {

		printf("Welcome to Harbor Game.\n");
		//printf("Step: %i\n", i);
		
		i++;

		l.Print();
		l.HandleInput();

		ClearSceen();
	}
}

void GameLoop::ClearSceen() const
{
	//system("cls");
}