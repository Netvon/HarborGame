#include "stdafx.h"
#include "Player.h"
#include "GameException.h"

Player::Player() : gold(0)
{
}

void Player::RepairShip(size_t gold, size_t steps)
{
	if (ship == nullptr)
		return;

	if (ship->GetIsAtFullHealth())
		return;

	while (!ship->GetIsAtFullHealth()) {
		ship->AddHealth(steps);
		SubtractGold(gold);
	}
}

void Player::ReplaceShip(Ship * newShip, double retainMultiplier)
{
	if (ship != nullptr) {
		auto percentageOfPrice = ship->GetPrice() * retainMultiplier;
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

void Player::AddCannonToShip(Cannon & cannon, int amount)
{
	if (ship == nullptr)
		return;

	if (gold < cannon.GetPrice() * amount)
		throw GameException("Not enough money");
	
	ship->AddCannon(cannon, amount);
	SubtractGold(cannon.GetPrice() * amount);
}

void Player::SellCannonToHarbor(Cannon & cannon, Harbor & harbor, double retainMultiplier)
{
	harbor.SellCannon(cannon);
	AddGold(
		static_cast<size_t>(cannon.GetPrice() * retainMultiplier)
	);

	ship->RemoveCannon(cannon);
}

void Player::AddProductToShip(Product & product, int amount)
{
	if (ship == nullptr)
		return;

	if (gold < product.GetPrice() * amount)
		throw GameException("Not enough money");

	ship->AddProduct(product, amount);
	SubtractGold(product.GetPrice() * amount);
}

//void Player::SellProductToHarbor(Product & product, Harbor & harbor, size_t amount)
//{
//	harbor.SellProduct(product, amount);
//	AddGold(
//		static_cast<size_t>(product.GetPrice() * amount)
//	);
//
//	ship->RemoveProduct(product, amount);
//}
