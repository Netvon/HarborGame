#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "SmrtPtr.h"
#include "SeaLocation.h"

#include <cstdio>
#include <iostream>

using namespace std;

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
	HarborLocation* l = dynamic_cast<HarborLocation*>(locations.get(0));

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