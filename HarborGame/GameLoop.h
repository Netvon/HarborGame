#pragma once
#include "Location.h"
#include "InputManager.h"

#include "Vector.h"
#include "Ship.h"
#include "Harbor.h"
#include "SmrtPtr.h"

#include "State.h"

class GameLoop
{
public:
	GameLoop(State* gameState, const String& name);
	~GameLoop();

	void Start();
private:
	
	bool quit = false;

	void ClearSceen() const;

	InputManager inputManager;
	Vector<Location*> locations;
	Vector<Ship> ships;
	Vector<Harbor> harbors;

	State * gameState;

	String name;
};

