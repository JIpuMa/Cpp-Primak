#include <stdio.h>

int main()
{
	printf("Input string: ");
	const int N = 255;
	char str[N];
	fgets(str, N, stdin);

	int numFirstComma = 0;
	int numLastComma = 0;
	int numAllCommas = 0;

	int len = sizeof(str);
	for (int index = 0; index < len; ++index)
	{
		if (str[index] == ',')
		{
			++numAllCommas;
			numLastComma = index+1;
			if (numAllCommas == 1)
			{
				numFirstComma = index+1;
			}
		}
	}
	printf("Number of the first comma: %d\n", numFirstComma);
	printf("Number of the last comma: %d\n", numLastComma);
	printf("Number of commas: %d", numAllCommas);

	return 0;
}