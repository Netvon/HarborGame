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
	virtual void PrintOptions() const 
	{
		printf("=========\nOptions\n");
		for (size_t i = 0; i < options.size(); i++)
		{
			auto o = options.get(i);
			printf(" %i. %s\n", o.number, o.name.c_str());
		}
		printf("=========\n");
	}	

	void AddOption(unsigned int number, const char * option) 
	{
		options.push_back({ number, option });
	}

	void Print() const {
		PrintWelcomeMessage();
		PrintOptions();
	}

	void HandleInput() {
		int option = manager.GetInput(static_cast<unsigned int>(options.size()));

		for (size_t i = 0; i < options.size(); i++)
		{
			auto o = options.get(i);
			if (o.number == option) {
				HandleOptionSelected(o);
				return;
			}
		}
	}

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

private:
	Vector<Option> options;
	InputManager manager;
	String name;

	State * gameState;

	virtual void HandleOptionSelected(const Option& option) = 0;
};
