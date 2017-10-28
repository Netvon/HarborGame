#include "stdafx.h"
#include "FileParser.h"

#include "Vector.h"
#include "String.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

FileParser::FileParser()
{

}


FileParser::~FileParser()
{

}


Vector<String> FileParser::ParseFile(const char* path, const char comment)
{
	ifstream infile;
	int lineNumber = 0;

	Vector<String> AllLines;
	
	infile.open(path, ifstream::in);
	if (infile.is_open())
	{
		while (infile.good() && !infile.eof())
		{
			String currentLine;
			char currentChar = 0;

			while (currentChar != '\n' && !infile.eof()) {
				infile.get(currentChar);

				if (currentLine.size() == 0 && currentChar == comment)
					break;

				if (currentChar == '\n') {
					currentLine += '\0';
					break;
				}

				currentLine += currentChar;
			}

			if (currentLine.size() == 0 && currentChar == comment)
				continue;

			// check for header lines
			if (lineNumber == 0) {
				lineNumber++;
				continue;
			}
				
			AllLines.push_back(currentLine);
		
			lineNumber++;
		}

		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	return AllLines;
}