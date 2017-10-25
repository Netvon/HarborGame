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

	Start();
}

GameLoop::~GameLoop()
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		delete locations.get(i);
		/*if (DeleteIf<HarborLocation*>(locations.get(i)))
			continue;

		if (DeleteIf<SeaLocation*>(locations.get(i)))
			continue;*/
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

template<class T>
bool GameLoop::DeleteIf(Location* pointer)
{
	if (pointer == nullptr)
		return true;

	auto val = dynamic_cast<T>(pointer);

	if (val != nullptr) {
		delete val;
		return true;
	}

	return false;
}