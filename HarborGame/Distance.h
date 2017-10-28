#pragma once
#include "stdafx.h"
#include "String.h"

class Distance {

public:
	Distance(const String to, size_t distance)
		: to(to), distance(distance) { }

	const String& getTo() const {
		return to;
	}

	const size_t& getDistance() const {
		return distance;
	}

private:
	String to;
	size_t distance;
};