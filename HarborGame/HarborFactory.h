#pragma once

#include "Harbor.h"

class HarborFactory
{
public:
	static Harbor CreateHarbor(String& pricesBlueprint, String& amountBlueprint, String& distancesBlueprint, Vector<String> productNames, Vector<String> harborNames);
private:
	HarborFactory() {};
};

