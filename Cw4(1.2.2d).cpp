#include <stdio.h>
#include <cmath>

int main()
{
	double x;
	printf("x=");
	scanf_s("%lf", &x);

	int n, i;
	printf("n=");
	scanf_s("%d", &n);

	double y;
	y = 0;
	for (i = 1; i < n + 1; i++) {
		y += pow(x, pow(i, 2));
	}
	printf("y=%g", y);
}