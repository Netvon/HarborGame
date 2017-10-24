#pragma once
#include "Option.h"
#include "InputManager.h"
#include <functional>
#include "Vector.h"

using namespace std;

class Location
{
public:
	Location() 
	{
		options = Vector<Option>();
	}

	virtual ~Location() {};

	virtual void PrintWelcomeMessage() const = 0;
	virtual void PrintOptions() const 
	{
		printf("=========\nOptions\n");
		for (size_t i = 0; i < options.size(); i++)
		{
			Option o = options.get(i);
			printf(" %i. %s\n", o.number, o.name.c_str());
		}
		printf("=========\n");
	}	

	void AddOption(unsigned int number, const char * option) 
	{
		options.push_back(Option(number, option));
	}

	void Print() const {
		PrintWelcomeMessage();
		PrintOptions();
	}

	void HandleInput() {
		int option = manager.GetInput(static_cast<unsigned int>(options.size()));

		for (size_t i = 0; i < options.size(); i++)
		{
			Option o = options.get(i);
			if (o.number == option) {
				HandleOptionSelected(o);
				return;
			}
		}
	}

protected:
	const InputManager* GetInputManager() const {
		return &manager;
	}

private:
	Vector<Option> options;
	InputManager manager;

	virtual void HandleOptionSelected(Option option) = 0;
};
