#include <stdio.h>
#include <cmath>

double half_len(double a, double b, double eps)
{
	if (b - a < eps)
	{
		return (a + b) / 2;
	}
	double z = (a + b) / 2;

	if (tan(z) - z < 0)
	{
		return half_len(z, b, eps);
	}
	else
	{
		return half_len(a, z, eps);
	}
}

int main()
{
	double a = 0.001, b = 1.5;
	double x, eps;

	do
	{
		printf("Input eps>0\n");
		scanf_s("%lf", &eps);
	} while (eps <= 0);

	x = half_len(a, b, eps);

	printf("x=%lf", x);
}