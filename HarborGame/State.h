#pragma once
#include "stdafx.h"
#include "Vector.h"
#include "InputManager.h"
#include "Location.h"
#include "Harbor.h"
#include "Ship.h"
#include "GameLoader.h"
#include "Player.h"

class Location;

class State
{
public:
	State() : quit(false) { };
	~State();

	bool GetQuitState() const;
	void SetQuitState(bool newState);

	template<class TLocation>
	void AddLocation(const String& name);

	Location* GetLocation(const String& name) const;
	Location* GetCurrentLocation() const;

	void NavigateToLocation(const String& locationName, const String& param);

	void LoadShipAssets(const String& filePath);
	void LoadHarborAssets(
		const String& goodsPricesFilePath,
		const String& goodsAmountsFilePath,
		const String& harborDistancesFilePath
	);

	size_t GetShipAmount();
	Ship* GetShip(size_t index);
	Ship* GetShip(const String& name);
	Harbor* GetHarbor(size_t index);
	Harbor* GetHarbor(const String& name);
	Player& GetPlayer();
	const Player& GetPlayer() const;
	bool GetPlayerHasShip() const;

private:
	bool quit;

	Vector<Location*> locations;
	InputManager inputManager;

	Vector<Ship> ships;
	Vector<Harbor> harbors;

	int currentLocation = -1;

	GameLoader loader;
	Player player;
	
};

template<class TLocation>
inline void State::AddLocation(const String& name)
{
	locations.push_back(new TLocation(name));

	GetLocation(name)->SetGameState(this);
}
