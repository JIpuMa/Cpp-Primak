#include <stdio.h>
#include <cmath>

int main()
{
	int r;
	printf("r = ");
	scanf_s("%d", &r);

	double A, B, C;
	do
	{
		printf("Input 3 angles: ");
		scanf_s("%lf %lf %lf", &A, &B, &C);
	} while (A + B + C != 180);

	const double pi = 3.14159265;

	double sA, sB, sC;
	sA = sin(A * pi / 180);
	sB = sin(B * pi / 180);
	sC = sin(C * pi / 180);

	double a, b, c;
	a = r / (2 * sA);
	b = r / (2 * sB);
	c = r / (2 * sC);

	double S, p;
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("S = %lf", S);
}