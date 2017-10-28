#include "Vector.h"
#include "String.h"

#pragma once
class FileParser
{
public:
	FileParser();
	~FileParser();

	Vector<String> ParseFile(const char* path, const char comment = '#');
private:
	const char * path;
};



