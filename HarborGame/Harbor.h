#include "Product.h"

#pragma once
class Harbor
{
public:
	Harbor(String name, Vector<Product> products) :
		name(name),
		products(products)
	{ };

	Harbor() { };
	~Harbor();

	Vector<Product> GetProducts() const;
	void AddProduct(Product product);

	const String& GetName() const;

private:
	Vector<Product> products;
	String name;
};

