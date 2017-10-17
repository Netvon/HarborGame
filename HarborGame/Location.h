#pragma once
#include "Option.h"
#include "InputManager.h"
#include <functional>

using namespace std;

class Location
{
public:
	Location(unsigned int optionAmount) 
	{
		options = new Option[optionAmount];
	}

	virtual ~Location() 
	{
		if(options != nullptr)
			delete[] options;
	};

	virtual void PrintWelcomeMessage() const = 0;
	virtual void PrintOptions() const 
	{
		printf("=========\nOptions\n");
		for (size_t i = 0; i < optionsCount; i++)
		{
			Option o = options[i];
			printf(" %i. %s\n", o.number, o.name);
		}
		printf("=========\n");
	}	

	void AddOption(unsigned int number, const char * option) 
	{
		options[optionsCount] = Option(number, option);
		optionsCount++;
	}

	void Print() const {
		PrintWelcomeMessage();
		PrintOptions();
	}

	void HandleInput() {
		int option = manager.GetInput(optionsCount);

		for (size_t i = 0; i < optionsCount; i++)
		{
			Option* o = &options[i];
			if (o->number == option) {
				HandleOptionSelected(*o);
				return;
			}
		}
	}

protected:
	const InputManager* GetInputManager() const {
		return &manager;
	}

private:
	unsigned int optionsCount;
	Option * options = nullptr;
	InputManager manager;

	virtual void HandleOptionSelected(Option option) = 0;
};
