#pragma once
#include "Location.h"
#include "InputManager.h"

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
};

