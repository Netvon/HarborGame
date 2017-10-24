#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "SmrtPtr.h"

#include <cstdio>
#include <iostream>

using namespace std;

GameLoop::GameLoop()
{
	locations.push_back(SmrtPtr<HarborLocation>(new HarborLocation()));
}

GameLoop::~GameLoop()
{
	
}

void GameLoop::Start()
{
	HarborLocation l = locations.get(0).value();

	int i = 0;

	while (!State::Instance().GetQuitState()) {

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