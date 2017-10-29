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
	void CreateOptions();
	void PrintWelcomeMessage() const override;

private:
	void AddGoodsOptions();
	void AddShipOptions();
	void AddCannonOptions();
	void HandleOptionSelected(const Option& option) override;
	void HandleCannonOption(const Option & option);
	void HandleShipOption(const Option & option);
	Harbor* currentHarbor = nullptr;
	String mode;
	String extraMessage;
	String navParam;
};

