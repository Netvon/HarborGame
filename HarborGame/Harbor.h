#include "Product.h"

#pragma once
class Harbor
{
public:
	Harbor(String name) :
		name(name) 
	{

	}
		;

	Harbor() {};
	~Harbor();

	Vector<Product> getProducts() const;
	String getName() const;
private:
	Vector<Product> products;
	String name;
};

