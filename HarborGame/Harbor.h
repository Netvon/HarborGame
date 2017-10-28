#include "Product.h"

#pragma once
class Harbor
{
public:
	Harbor(String name, Vector<Product> products) :
		name(name),
		products(products)
	{

	};

	Harbor() { };
	~Harbor();

	Vector<Product> getProducts() const;
	const String& GetName() const;
	void setName(const String& newName);

private:
	Vector<Product> products;
	String name;
};

