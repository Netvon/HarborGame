#include "stdafx.h"
#include "Location.h"

void Location::PrintOptions() const
{
	printf("\n=========\nOptions\n");
	for (size_t i = 0; i < options.size(); i++)
	{
		auto o = options.get(i);
		printf(" %i. %s\n", o.number, o.name.c_str());
	}
	printf("=========\n");
}

void Location::PrintStats() const
{
	auto& player = GetState().GetPlayer();
	printf("[ Gold: %llu ]", player.GetGold());

	if (GetState().GetPlayerHasShip()) {
		printf(" [ Ship: %s, ", player.GetShipName().c_str());
		printf("%i/%i hp ]", player.GetShip().GetCurrentHealth(), player.GetShip().GetMaxHealth());

		printf(" [ Goods: %i/%i ]", 0, player.GetShip().GetMaxCargospace());
	}
	else {
		printf(" [ Ship: ---, --- hp ]");
		printf(" [ Goods: --- ]");
	}

	printf("\n\n");
}

void Location::AddOption(unsigned int number, const char * option)
{
	options.push_back({ number, option });
}

void Location::Print() const
{
	PrintStats();
	PrintWelcomeMessage();
	PrintOptions();
}

void Location::HandleInput()
{
	int option = manager.GetInput(static_cast<unsigned int>(options.size()));

	for (size_t i = 0; i < options.size(); i++)
	{
		auto o = options.get(i);
		if (o.number == option) {
			HandleOptionSelected(o);
			break;
		}
	}

	manager.AskForContinue();
}
