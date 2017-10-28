#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

const String & Player::GetShipName() const
{
	return ship.GetName();
}

const Ship & Player::GetShip() const
{
	return ship;
}

const size_t & Player::GetGold() const
{
	return gold;
}
