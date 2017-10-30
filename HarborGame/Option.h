#pragma once
#include "stdafx.h"

#include "String.h"

class Option {
public:
	Option() :number(0), name("") {};
	Option(size_t number, const char* name)
		: number(number), name(name) {};

	size_t number;
	String name;
};