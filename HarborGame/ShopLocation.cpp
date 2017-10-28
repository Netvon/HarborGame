#include "stdafx.h"
#include "ShopLocation.h"


ShopLocation::ShopLocation(const String & name) : Location(name)
{
	
}

void ShopLocation::NavigatedTo(const String & param)
{
	currentHarbor = GetState().GetHarbor(param);
}
