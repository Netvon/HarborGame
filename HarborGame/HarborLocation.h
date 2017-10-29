#pragma once
#include "Location.h"
#include "Product.h"
#include "Harbor.h"

class HarborLocation :
	public Location
{
public:
	HarborLocation() : HarborLocation("harbor") { }
	HarborLocation(const String& name);
	~HarborLocation() { };

	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;
	
private:
	void HandleOptionSelected(const Option& option) override;
	void HandleCannonShop();
	void HandleGoodsShop();
	void HandleBuyShip();
	Harbor* currentHarbor = nullptr;
};

