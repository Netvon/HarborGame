#include "stdafx.h"
#include "LeaveLocation.h"

LeaveLocation::LeaveLocation(const String & name) : Location(name)
{

}

void LeaveLocation::NavigatedTo(const String & param)
{
	currentHarbor = GetState().GetHarbor(param);

	ClearOptions();

	AddOption(1, "Go back to the harbor");
	AddOption(2, "Quit");

	for (size_t i = 0; i < currentHarbor->GetDistancesSize(); i++)
	{
		String name;

		name = currentHarbor->GetDistance(i).getTo();
		name = name + " ";
		name = name + "[ " + currentHarbor->GetDistance(i).GetDistance() + " Turns ]";

		AddOption(i + 3, name);
	}

}

void LeaveLocation::PrintWelcomeMessage() const
{
	printf("| Sad to see you leave %s captain, where do you wanna go?\n", currentHarbor->GetName().c_str());
}

void LeaveLocation::HandleOptionSelected(const Option & option)
{
	switch (option.number)
	{
	case 1:
		GetState().NavigateToLocation("harbor", currentHarbor->GetName());
		return;
	case 2:
		GetState().SetQuitState(true);
		return;
	default:
		break;
	}
}
