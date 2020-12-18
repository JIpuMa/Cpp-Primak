#include <stdio.h>
#include <cmath>

int main()
{
	double x;
	int n, i;
	printf("n=");
	scanf_s("%d", &n);
	printf("x=");
	scanf_s("%f", &x);

	i = 0;
	while (i < n) {
		x = sin(x);
		i++;
	}
	printf("y=%f", x);
}