#include "Vector.h"
#include "String.h"

#pragma once
class FileParser
{
public:
	FileParser();
	~FileParser();

	Vector<String> ParseFile(const char* path, const char comment = '#', size_t ignoreLines = 1) const;
private:
	const char * path;
};



