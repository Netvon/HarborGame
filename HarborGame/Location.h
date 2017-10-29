#pragma once
#include "Option.h"
#include "InputManager.h"
#include "Vector.h"
#include "State.h"

class State;

class Location
{
public:
	Location(const String& name)
		: name(name), options() { }

	Location()
		: name(""), options() { }

	virtual ~Location() { };

	virtual void NavigatedTo(const String& param) = 0;
	virtual void PrintWelcomeMessage() const = 0;
	virtual void PrintOptions() const;
	void PrintStats() const;
	void AddOption(unsigned int number, const char * option);
	void Print() const;

	void HandleInput();

	void SetGameState(State * newGameState) {
		gameState = newGameState;
	}

	const String& GetName() const {
		return name;
	}

protected:
	const InputManager* GetInputManager() const {
		return &manager;
	}

	State& GetState() {
		return *gameState;
	}

	const State& GetState() const {
		return *gameState;
	}

	void ClearOptions() {
		options.clear();
	}

private:
	Vector<Option> options;
	InputManager manager;
	String name;

	State * gameState;

	virtual void HandleOptionSelected(const Option& option) = 0;
};
