#include <stdio.h>

int main()
{
	int i, n;
	printf("n=");
	scanf_s("%d", &n);
	printf("%d!=1", n);
	for (i = 2; i < n + 1; i++)
	{
		printf("*%d", i);
	}
}