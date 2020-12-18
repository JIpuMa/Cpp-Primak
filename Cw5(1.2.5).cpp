#include <stdio.h>

int main()
{
	int y, i, n;
	printf("n=");
	scanf_s("%d", &n);
	y = 1;
	int ex = 0;
	printf("Which example do you want to see? (1/2): ");
	scanf_s("%d", &ex);

	if (ex == 1)
	{
		for (i = 1; i < n + 1; i++)
		{
			y *= i;
		}
	}
	else
	{
		for (i = n; i > 0; i--)
		{
			y *= i;
		}
	}
	printf("y=%d!=%d", n, y);
}