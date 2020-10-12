#include <stdio.h>
#include <cmath>

double f(double x)
{
	double fx;
	fx = 1 / (1 + exp(-x));
	return fx;
}

double dfdx(double x)
{
	double der_fx;
	der_fx = exp(-x) / pow(1 + exp(-x), 2);
	return der_fx;
}

int main()
{
	double x;
	printf("x = ");
	scanf_s("%lf", &x);

	double fx;
	fx = f(x);
	printf("f(x) = %lf", fx);

	double der_fx;
	der_fx = dfdx(x);
	printf("\nf\'(x) = %lf", der_fx);
}