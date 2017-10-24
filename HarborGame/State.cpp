#include "stdafx.h"
#include "State.h"


State & State::Instance()
{
	static State instance;
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
