#include "stdafx.h"
#include "BattleLocation.h"
#include "RandomPirateshipGenerator.h"
#include "RandomNumber.h"

BattleLocation::BattleLocation(const String & name) : Location(name)
{
}

void BattleLocation::NavigatedTo(const String & param)
{
	auto ships = GetState().GetShips();
	pirateship = RandomPirateshipGenerator::Instance().GeneratePirateship(ships);

	AddOption(1, "Quit");
	AddOption(2, "Schoot");
	AddOption(3, "Retreat");
	AddOption(4, "Surrender");
}

void BattleLocation::PrintWelcomeMessage() const
{
	printf("| You've have encounterd an pirateship captain, prepare for battle!");
}

void BattleLocation::HandleOptionSelected(const Option & option)
{
	switch (option.number)
	{
	case 1:
		GetState().SetQuitState(true);
		return;
	case 2:
		Shoot();
		return;
	case 3:
		Retreat();
		return;
	case 4:
		Surrender();
		return;
	default:
		break;
	}
}

void BattleLocation::Shoot()
{
}

void BattleLocation::Retreat()
{
	auto playership = GetState().GetPlayer().GetShip();

	// If you're ships light and enemy is light
	if (playership.HasLightTrait() && pirateship.HasLightTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if(randomnumber <= 50)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships light and enemy is medium
	if (playership.HasLightTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 60)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships light and enemy is heavy
	if (playership.HasLightTrait() && pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 75)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships medium and enemy is light
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && pirateship.HasLightTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 30)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships medium and enemy is medium
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 40)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships medium and enemy is heavy
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 55)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships light and enemy is light
	if (playership.HasInertTrait() && pirateship.HasLightTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 5)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships light and enemy is medium
	if (playership.HasInertTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 15)
			GetState().NavigateToLocation("sea", "");
	}

	// If you're ships light and enemy is heavy
	if (playership.HasInertTrait() && pirateship.HasInertTrait()) {
		size_t randomnumber = RandomNumber::Instance().Get<size_t>(1, 100);
		if (randomnumber <= 30)
			GetState().NavigateToLocation("sea", "");
	}
}

void BattleLocation::Surrender()
{
	auto ship = GetState().GetPlayer().GetShip();
	ship.Clear();
}


