#pragma once
class InputManager
{
public:
	InputManager(const char * prompt = ">", unsigned int maxInputSize = 1) 
		: promptChar(prompt), maxInputSize(maxInputSize) 
	{ };

	int GetInput(unsigned int maxNumber) const;
	void AskForContinue() const;

private:
	const char * promptChar;
	unsigned int maxInputSize;

	void PrintInputError(unsigned int maxNumber) const;
};

