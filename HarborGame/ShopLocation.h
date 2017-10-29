#pragma once
#include "Location.h"
class ShopLocation :
	public Location
{
public:
	ShopLocation() : ShopLocation("harbor") { }
	ShopLocation(const String& name);
	~ShopLocation() { };

	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;

private:
	void HandleOptionSelected(const Option& option) override;
	Harbor* currentHarbor = nullptr;
	String mode;
};

