#pragma once

#include "Harbor.h"

class HarborFactory
{
public:
	static Harbor CreateHarbor(String& pricesBlueprint, String& amountBlueprint, Vector<String> productNames);
private:
	HarborFactory() {};
};

