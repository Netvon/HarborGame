#include "stdafx.h"
#include "FileReadException.h"

FileReadException::FileReadException(const String & why)
{
	reason = why;
}

const char * FileReadException::what() const
{
	return reason;
}
