#pragma once
#include "stdafx.h"
#include "String.h"

class Distance {

public:
	Distance(const String from, const String to, size_t distance)
		: from(from), to(to), distance(distance) { }

	const String& getFrom() const {
		return from;
	}

	const String& getTo() const {
		return to;
	}

	const size_t& getDistance() const {
		return distance;
	}

private:
	String from;
	String to;
	size_t distance;
};