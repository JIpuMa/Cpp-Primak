#include <stdio.h>
#include <cmath>

int main()
{
	int r, n;
	printf("n=");
	scanf_s("%d", &n);
	r = 1;
	while (pow(2, r) < n)
	{
		r++;
	}
	printf("r=%d", r);
}