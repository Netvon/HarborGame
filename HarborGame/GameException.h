#pragma once
#include "stdafx.h"
#include <stdexcept>
#include "String.h"

class GameException
	: std::exception
{
public:
	GameException(const String& why);
	const char* what() const override;

private:
	String reason;
};

