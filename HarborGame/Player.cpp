#include "stdafx.h"
#include "Player.h"


Player::Player() : gold(20000)
{
}

void Player::RepairShip() const
{
}

void Player::ReplaceShip(Ship & newShip) const
{
}

const String & Player::GetShipName() const
{
	if(ship != nullptr)
		return ship->GetName();

	return "";
}

Ship & Player::GetShip() const
{
	return *ship;
}

const size_t & Player::GetGold() const
{
	return gold;
}
