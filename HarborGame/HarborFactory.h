#pragma once

#include "Harbor.h"

class HarborFactory
{
public:
	static Harbor CreateHarbor(String& pricesBlueprint, String& amountBlueprint);
private:
	HarborFactory() {};
};

