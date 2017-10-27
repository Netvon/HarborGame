#include "stdafx.h"
#include "HarborFactory.h"
#include "Harbor.h"

using namespace std;

HarborFactory::HarborFactory()
{
}


HarborFactory::~HarborFactory()
{
}

Harbor HarborFactory::CreateHarbor(String& blueprint)
{
	Vector<String> splittedBlueprint{ String::split(blueprint.c_str(), ";") };

	cout << splittedBlueprint.get(0) << endl;

	String name{ splittedBlueprint.get(0) };

	Harbor harbor{ name };

	return harbor;
}