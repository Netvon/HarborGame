#pragma once

#include "Harbor.h"

class HarborFactory
{
public:
	HarborFactory();
	~HarborFactory();

	Harbor CreateHarbor(String& blueprint);
};

