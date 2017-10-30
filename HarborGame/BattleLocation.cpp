#include "stdafx.h"
#include "BattleLocation.h"
#include "RandomPirateshipGenerator.h"
#include "RandomNumber.h"

BattleLocation::BattleLocation(const String & name) : Location(name)
{
	AddOption(1, "Fire cannons at the Ship");
	AddOption(2, "Try to Retreat");
	AddOption(3, "Surrender to the Pirates");
	AddOption(4, "Quit");
}

void BattleLocation::NavigatedTo(const String & param)
{
	auto ships = GetState().GetShips();
	pirateship = RandomPirateshipGenerator::Instance().GeneratePirateship(ships);
}

void BattleLocation::PrintWelcomeMessage() const
{
	printf("| You've have encounterd a Pirate Ship Captain, prepare for battle!\n\n");
	printf("| Here's the whats-what on the Pirate Ship, cap'n.\n");

	printf("| - [ Name: %s ] [ %llu/%llu hp ] [ %llu cannons ]\n", pirateship.GetName().c_str(), pirateship.GetCurrentHealth(), pirateship.GetMaxHealth(), pirateship.GetCannonsAmount());
}

void BattleLocation::HandleOptionSelected(const Option & option)
{
	switch (option.number)
	{
	case 1:
		Shoot();
		break;
	case 2:
		Retreat();
		break;
	case 3:
		Surrender();
		break;
	case 4:
		GetState().SetQuitState(true);
		break;
	default:
		break;
	}
}

void BattleLocation::Shoot()
{
	auto& ship = GetState().GetPlayer().GetShip();

	int damageToPirate = GetDamage(ship);
	pirateship.SubtractHealth(to_sizet(damageToPirate));

	printf("| We fired at the Pirate Ship! We did a total of [ %i damage ].\n", damageToPirate);

	if (pirateship.GetCurrentHealth() > 0) {

		FirePirateCannons();
	}
	else {
		printf("| Well done captain, we destroyed the pirate vessel.\n");
	}
}

void BattleLocation::FirePirateCannons()
{
	auto& ship = GetState().GetPlayer().GetShip();
	printf("| Oh no, they're aiming there cannons at us. Prepare for impact!\n");

	int damageToCaptain = GetDamage(pirateship);
	ship.SubtractHealth(to_sizet(damageToCaptain));

	printf("| Damage Report! -- they did [ %i damage ] sir.\n", damageToCaptain);
}

int BattleLocation::GetDamage(Ship & ship)
{
	int damage = 0;
	for (size_t i = 0; i < ship.GetUniqueCannonAmount(); i++)
	{
		auto& cannon = ship.GetCannon(i);
		for (size_t y = 0; y < cannon.GetAvailable(); y++)
		{
			damage += cannon.GenerateRandomDamage();
		}
	}

	return damage;
}

void BattleLocation::Retreat()
{
	auto playership = GetState().GetPlayer().GetShip();

	int randomnumber = RandomNumber::Instance().Get<int>(1, 100);
	int chance = 0;

	// If you're ships light and enemy is light
	if (playership.HasLightTrait() && pirateship.HasLightTrait()) {
		chance = 50;
	}

	// If you're ships light and enemy is medium
	if (playership.HasLightTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		chance = 60;
	}

	// If you're ships light and enemy is heavy
	if (playership.HasLightTrait() && pirateship.HasInertTrait()) {
		chance = 75;
	}

	// If you're ships medium and enemy is light
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && pirateship.HasLightTrait()) {
		chance = 30;
	}

	// If you're ships medium and enemy is medium
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		chance = 40;
	}

	// If you're ships medium and enemy is heavy
	if (!playership.HasLightTrait() && !playership.HasInertTrait() && pirateship.HasInertTrait()) {
		chance = 55;
	}

	// If you're ships light and enemy is light
	if (playership.HasInertTrait() && pirateship.HasLightTrait()) {
		chance = 5;
	}

	// If you're ships light and enemy is medium
	if (playership.HasInertTrait() && !pirateship.HasLightTrait() && !pirateship.HasInertTrait()) {
		chance = 15;
	}

	// If you're ships light and enemy is heavy
	if (playership.HasInertTrait() && pirateship.HasInertTrait()) {
		chance = 30;
	}

	if (randomnumber <= chance) {
		printf("| We succesfully fled from the Pirates! Let's continue our journey.\n");
		GetState().NavigateToLocation("sea");
	}
	else {
		printf("| We tried to sail away from the pirates, but they followed us!\n");
		FirePirateCannons();
	}
}

void BattleLocation::Surrender()
{
	// TODO: insert some flavour text here

	auto ship = GetState().GetPlayer().GetShip();
	ship.Clear();

	GetState().NavigateToLocation("sea");
}


