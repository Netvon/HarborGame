#include "stdafx.h"
#include "FileParser.h"

#include "Vector.h"
#include "String.h"
#include <iostream>
#include <fstream>
#include "FileReadException.h"

using std::ifstream;
using std::cout;

Vector<String> FileParser::ParseFile(const char* path, size_t ignoreLines, const char comment) const
{
	ifstream infile;
	size_t lineNumber = 0;

	Vector<String> AllLines;
	
	infile.open(path, ifstream::in);
	if (infile.is_open())
	{
		while (infile.good() && !infile.eof())
		{
			bool isComment = false;

			String currentLine;
			char currentChar = 0;

			while (currentChar != '\n' && !infile.eof()) {
				infile.get(currentChar);

				if (currentLine.isEmpty() && currentChar == comment) {
					isComment = true;
				}

				if (currentChar == '\n') {
					currentLine += '\0';
					break;
				}

				if(!isComment)
					currentLine += currentChar;
			}

			if (currentLine.isEmpty())
				continue;

			// check for header lines
			if (ignoreLines > 0 && lineNumber <= ignoreLines - 1) {
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
		String error = "Failed to open '";
		error += path;
		error += "'";

		throw FileReadException(error);
	}

	return AllLines;
}