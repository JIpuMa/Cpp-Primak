#include <stdio.h>

int main()
{
	int n, x;
	int i, j, k;
	printf("n=");
	scanf_s("%d", &n);
	x = n * 2;
	for (i = 2; i <= x; i++)
	{
		k = 0;
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 1) {
			printf("%d\n", i);
		}
	}
}