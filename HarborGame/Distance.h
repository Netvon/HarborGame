#pragma once
#include "stdafx.h"
#include "String.h"

class Distance {

public:
	Distance(const String name, size_t turns)
		: name(name), turns(turns) { }

	Distance() {};

	const String& GetDestinationName() const {
		return name;
	}

	const size_t& GetTurns() const {
		return turns;
	}

private:
	String name;
	size_t turns;
};