#include "stdafx.h"
#include "State.h"


State * State::instance = nullptr;

State * State::Instance()
{
	if (instance == nullptr)
		instance = new State();

	return instance;
}

bool State::GetQuitState() const
{
	return quit;
}

void State::SetQuitState(bool newState)
{
	quit = newState;
}
