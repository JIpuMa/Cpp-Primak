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
	for (i = n; i >= 0; i--) {
		y += pow(x, i);
	}
	printf("y=%g", y);
}