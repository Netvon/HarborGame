#include "Product.h"
#include "Cannon.h"
#include "Distance.h"

#pragma once
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
	~Harbor();

	const Vector<Product>& GetProducts() const;

	const Cannon& GetCannon(size_t index) const;
	Cannon& GetCannon(size_t index);
	size_t GetCannonSize() const;

	void SellCannon(Cannon& cannon);
	void IncreaseCannonStock(String& type, size_t byAmount);

	void Randomize();
	void RandomizeProductAvailability();
	void RandomizeCannonAvailability();

	Vector<Distance> getDistances() const;
	const String& GetName() const;

private:
	Vector<Product> products;
	Vector<Cannon> cannons;
	Vector<Distance> distances;
	String name;
};

