#include <stdio.h>

double f(double x, double a)
{
	double fx;
	if (x < 0)
	{
		fx = a * x;
	}
	else
	{
		fx = 0;
	}
	return fx;
}

double dfdx(double x, double a)
{
	double der_fx;
	if (x < 0)
	{
		der_fx = a;
	}
	else
	{
		der_fx = 0;
	}
	return der_fx;
}

int main()
{
	double x, a;
	printf("x = ");
	scanf_s("%lf", &x);
	printf("a = ");
	scanf_s("%lf", &a);

	double fx;
	fx = f(x,a);
	printf("f(x) = %g", fx);

	double der_fx;
	der_fx = dfdx(x, a);
	printf("\nf\'(x) = %g", der_fx);
}