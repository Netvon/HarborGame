#pragma once

#include "Product.h"
#include "Cannon.h"
#include "Distance.h"
#include "Player.h"

class Player;

class Harbor
{
public:
	Harbor(String name, const Vector<Product>& products, const Vector<Cannon>& cannons, const Vector<Distance>& distances) :
		name(name),
		products(products),
		cannons(cannons),
		distances(distances)
	{ };

	Harbor() { };

	const Product& GetProduct(size_t index) const;
	const Product& GetProduct(const String& name) const;
	Product& GetProduct(size_t index);
	
	bool GetProductIsInStock(size_t index) const;

	void BuyProduct(Player& forPlayer, Product& product, size_t amount);
	void SellProduct(Player & forPlayer, Product & product, size_t amount, size_t price);

	const Cannon& GetCannon(size_t index) const;
	Cannon& GetCannon(size_t index);
	
	bool GetCannonIsInStock(size_t index) const;

	void BuyCannon(Player& forPlayer, Cannon& cannon, size_t amount);
	void SellCannon(Cannon& cannon);

	void Randomize();
	void RandomizeProductAvailability();
	void RandomizeCannonAvailability();

	Vector<Distance> getDistances() const;
	const String& GetName() const;

	size_t GetProductsSize() const;
	size_t GetCannonSize() const;

private:

	void IncreaseProductStock(const String& name, size_t byAmount);
	void DecreaseProductStock(const String& name, size_t byAmount);

	void IncreaseCannonStock(const String& type, size_t byAmount);
	void DecreaseCannonStock(const String& type, size_t byAmount);

	Vector<Product> products;
	Vector<Cannon> cannons;
	Vector<Distance> distances;
	String name;
};

