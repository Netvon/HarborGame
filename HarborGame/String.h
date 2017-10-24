#pragma once
#include <cstddef>

#include "Vector.h"

#include <String.h>
#include <stddef.h>

class String {
private:
	Vector<char> vector;
public:
	String() :vector(1) {};

	String(const char* string) : String()
	{
		size_t length = strlen(string) + 1;

		for (size_t i = 0u; i < length; i++)
		{
			vector.push_back(string[i]);
		}
	}

	String(String& string) : String()
	{
		size_t length = string.size();

		for (size_t i = 0u; i < length; i++)
		{
			vector.push_back(string[i]);
		}
	}

	String& operator=(const char* string)
	{
		size_t length = strlen(string) + 1;
		vector = Vector<char>(length);

		for (size_t i = 0u; i < length; i++)
		{
			vector.push_back(string[i]);
		}
	}

	String& operator+=(const char* string)
	{
		size_t length = strlen(string) + 1;

		vector.pop_back();

		for (size_t i = 0u; i < length; i++)
		{
			vector.push_back(string[i]);
		}

		return *this;
	}

	bool operator==(const String& string)
	{
		return strcmp(c_str(), string.c_str()) == 0;
	}

	bool operator==(const char* string)
	{
		return strcmp(c_str(), string) == 0;
	}

	bool operator!=(String& string)
	{
		return strcmp(c_str(), string.c_str()) != 0;
	}

	bool operator!=(const char* string)
	{
		return strcmp(c_str(), string) != 0;
	}

	String operator+(const char* string)
	{
		String temp = String(*this);
		temp += string;

		return temp;
	}

	String operator+(String& string)
	{
		String temp = String(*this);
		temp += string;

		return temp;
	}

	String& operator+=(String& string)
	{
		size_t length = string.size();

		vector.pop_back();

		for (size_t i = 0u; i < length; i++)
		{
			vector.push_back(string[i]);
		}

		return *this;
	}

	String& operator+=(int number)
	{
		String string = String::parse(number);
		return *this += string;
	}

	String operator+(int number)
	{
		String string = String::parse(number);
		return *this + string;
	}

	const char operator[](std::size_t index) const
	{
		return vector.get(index);
	}

	size_t size() const {
		return vector.size();
	}

	const char* c_str() const {
		return vector.getArray();
	}

	operator const char*() const {
		return c_str();
	}

	bool contains(const char * string) const {
		return strstr(c_str(), string) != nullptr;
	}

	bool contains(const String& string) const {
		return strstr(c_str(), string.c_str()) != nullptr;
	}

	static Vector<String> split(const char * string, const char * delimiter) {
		size_t stringLen = strlen(string) + 1;

		char* stringArr = new char[stringLen];
		for (size_t i = 0; i < stringLen; i++)
		{
			stringArr[i] = string[i];
		}

		Vector<String> temp;

		char * safePointer;

		char * current = strtok_s(stringArr, delimiter, &safePointer);

		while (current != nullptr) {
			temp.push_back(current);
			current = strtok_s(nullptr, delimiter, &safePointer);
		}

		delete stringArr;
		return temp;
	}


	static String parse(int number) {
		char buffer[sizeof(int) * 8 + 1];

		_itoa_s(number, buffer, sizeof(int) * 8 + 1, 10);

		return String(buffer);
	}
};