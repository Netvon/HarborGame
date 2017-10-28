#pragma once
#include "Location.h"
#include "InputManager.h"

#include "Vector.h"
#include "Ship.h"
#include "Harbor.h"
#include "SmrtPtr.h"

class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void Start();
private:
	
	bool quit = false;

	void ClearSceen() const;

	InputManager inputManager;
	Vector<Location*> locations;
	Vector<Ship> ships;
	Vector<Harbor> harbors;
};

