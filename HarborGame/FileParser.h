#pragma once
class FileParser
{
public:
	FileParser();
	~FileParser();

	void ParseFile(size_t elementsPerLine, const char* path);
};



