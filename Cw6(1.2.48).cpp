#include <stdio.h>
#include <cmath>

int main()
{
	int i, j, k, n;
	printf("n=");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			k = 0;
			for (j = 1; j <= i; j++)
			{
				if (i % j == 0)
				{
					k++;
				}
			}
			if (k == 2)
			{
				printf("%d\n", i);
			}
		}
	}
}