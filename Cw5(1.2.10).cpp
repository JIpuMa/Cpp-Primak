#include <stdio.h>
#include <cmath>

int main()
{
	float ans, m, k;
	printf("m=");
	scanf_s("%g", &m);
	k = 0;
	while (pow(4, k) <= m)
	{
		k++;
	}
	k--;
	printf("k=%g", k);
}