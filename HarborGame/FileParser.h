#include "Vector.h"
#include "String.h"

#pragma once
class FileParser
{
public:
	Vector<String> ParseFile(const char* path, size_t ignoreLines = 1, const char comment = '#') const;
};



