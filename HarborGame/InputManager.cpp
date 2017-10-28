#include "stdafx.h"
#include "InputManager.h"

#include <cstdio>
#include <iostream>

int InputManager::GetInput(unsigned int maxNumber = 1)
{
	unsigned int numberInput = 0;
	printf("> ");
	scanf_s("%i", &numberInput);

	while (numberInput == 0 || numberInput > maxNumber) {
		
		// clear, fixes inf loop
		char clear = getchar();
		while(clear != '\n')
			clear = getchar();

		PrintInputError(maxNumber);

		printf("> ");
		scanf_s(" %i", &numberInput);
	}

	return numberInput;
}

void InputManager::PrintInputError(unsigned int maxNumber) const
{
	printf("Input incorrect: Only numbers between 1 and %i are allowed\n", maxNumber);
}
