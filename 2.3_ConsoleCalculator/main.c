#include <stdio.h>
#include <stdlib.h>

#define EXIT_CODE_SUCCESS 0
#define EXIT_CODE_INVALID_INPUT -1

#define METHOD_ADD 43
#define METHOD_SUBSTRACT 45
#define METHOD_MULTIPLY 42
#define METHOD_DIVIDE 47

int main()
{
	char method = 0x0; // Invalid value for the following check

	printf("Please enter the calculation method, which you want to use(+,-,*,/): ");
	if (scanf_s("%c", &method) < 1 || (method != METHOD_ADD && method != METHOD_SUBSTRACT && method != METHOD_MULTIPLY && method != METHOD_DIVIDE))
	{
		printf("Invalid input! Abort ...");
		return EXIT_CODE_INVALID_INPUT;
	}

	int counter = 1;
	float result, read;
	printf("Please enter the numbers but be aware, that there is no overflow check!\n");

	// We write what the user should do, read and check the input
	while (printf("Input %d number: ", counter) > 0 && scanf_s("%f", &read) > 0 && read >= 0)
	{
		if (counter++ < 2) // We check the counter and then increment it
		{
			result = read;
			continue;
		}

		if (method == METHOD_ADD)
		{
			result += read;
		}
		else if (method == METHOD_SUBSTRACT)
		{
			result -= read;
		}
		else if (method == METHOD_MULTIPLY)
		{
			result *= read;
		}
		else
		{
			result /= read;
		}

		printf("Read numbers: %d.\nResult: %f\n\n", counter - 1, result); // We already increased the counter in the if ...
	}

	printf("Finished!");
	return EXIT_CODE_SUCCESS;
}
