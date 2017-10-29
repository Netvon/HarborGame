#include "stdafx.h"
#include "GameException.h"


GameException::GameException(const String & why)
{
	reason = why;
}

const char * GameException::what() const
{
	return reason;
}
