#include "stdafx.h"
#include "FileParser.h"

#include "Vector.h"
#include "String.h"
#include <iostream>
#include <fstream>

using namespace std;

FileParser::FileParser()
{

}


FileParser::~FileParser()
{

}


Vector<String> FileParser::ParseFile(const char* path)
{
	ifstream infile;
	int array[20];
	int i = 0;
	char cNum[256];
	Vector<String> AllLines;
	
	infile.open(path, ifstream::in);
	if (infile.is_open())
	{
		while (infile.good())
		{
			infile.getline(cNum, 256);

			auto str = strchr(cNum, '#');
			if (str - cNum == 0)
				continue;

			if (i == 0) {
				i++;
				continue;
			}
				
			AllLines.push_back(cNum);
		
			i++;
		}
		infile.close();
		return AllLines;
	}
	else
	{
		cout << "Error opening file";
	}
}