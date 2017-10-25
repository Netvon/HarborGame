#include "stdafx.h"
#include "GameLoop.h"
#include "HarborLocation.h"
#include "State.h"
#include "SmrtPtr.h"
#include "FileParser.h"

#include <cstdio>
#include <iostream>

using namespace std;

GameLoop::GameLoop()
{
	FileParser fp;
	fp.ParseFile("Files/schepen.csv");

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