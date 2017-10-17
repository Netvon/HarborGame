#pragma once
#include "stdafx.h"

#include <string.h>

class Option {
public:
	Option() :number(0), name("") {};
	Option(unsigned int number, const char* name)
		: number(number), name(name) {};

	unsigned int number;
	const char* name;
};