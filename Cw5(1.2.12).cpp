#include <stdio.h>

int main()
{
	double a;
	int i;
	printf("a=");
	scanf_s("%lf", &a);
	i = 1;
	while (1 + a != 1) {
		a /= 2;
		i++;
	}
	printf("a=%le", a);
	printf("\ni=%d", i);
}