#pragma once
#include "Location.h"
#include "String.h"
#include "Distance.h"
#include "Weather.h"

class SeaLocation :
	public Location
{
public:
	SeaLocation() : SeaLocation("sea") { }
	SeaLocation(const String& name);
	~SeaLocation() { };

	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;

private:
	void HandleOptionSelected(const Option& option) override;
	void GenerateShipReport() const;
	void DoTurn();

	void HandleWeather();

	String GetWeatherFlavour(Weather weather) const;

	String destination;
	int totalDistance;
	int currentDistance;
	size_t turn;

	bool shouldHaveEncounter;

	Weather currentWeather;
};

