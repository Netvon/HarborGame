#include "stdafx.h"
#include "Player.h"


Player::Player() : gold(0)
{
}

void Player::RepairShip() const
{
}

void Player::ReplaceShip(Ship * newShip)
{
	if (ship != nullptr) {
		auto percentageOfPrice = ship->GetPrice() * 0.5;
		AddGold(static_cast<size_t>(percentageOfPrice));
	}

	if (newShip != nullptr) {
		SubtractGold(static_cast<size_t>(newShip->GetPrice()));
	}

	ship = new Ship(newShip);
}

void Player::AddGold(size_t addGoldAmount)
{
	gold += addGoldAmount;
}

void Player::SubtractGold(size_t subtractAmount)
{
	gold -= subtractAmount;
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

bool Player::GetIsBroke() const
{
	return gold == 0;
}
