#pragma once

#include "Harbor.h"

class HarborFactory
{
public:
	static Harbor CreateHarbor(String& blueprint);
private:
	HarborFactory() {};
};

