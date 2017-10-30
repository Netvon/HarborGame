#pragma once
#include "stdafx.h"
#include <stdexcept>
#include "String.h"

class FileReadException
	: std::exception
{
public:
	FileReadException(const String& why);
	const char* what() const override;

private:
	String reason;
};