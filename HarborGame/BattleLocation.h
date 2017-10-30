#pragma once
#include "Ship.h"

#include "Location.h"
class BattleLocation :
	public Location
{
public:
	BattleLocation() : BattleLocation("battle") { }
	BattleLocation(const String& name);
	~BattleLocation() { };
	 
	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;
private:
	Ship pirateship;

	void HandleOptionSelected(const Option& option) override;
	void Shoot();
	void FirePirateCannons();
	int GetDamage(Ship & ship);
	void Retreat();
	void Surrender();
};

