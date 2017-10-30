#pragma once
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
	void HandleOptionSelected(const Option& option) override;
};

