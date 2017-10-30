#pragma once
#include "Location.h"
#include "InputManager.h"

#include "Vector.h"
#include "Ship.h"
#include "Harbor.h"

#include "State.h"

class GameLoop
{
public:
	GameLoop(State* gameState, const String& name);

	void Start() const;
private:
	
	bool quit = false;

	void ClearSceen() const;

	State * gameState;
	String name;
};

