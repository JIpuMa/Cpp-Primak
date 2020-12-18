#include <stdio.h>

int main()
{
	int y, i, n;
	printf("n=");
	scanf_s("%d", &n);
	y = 1;
	for (i = n; i > 0; i -= 2) {
		y *= i;
	}
	printf("y=%d!!=%d", n, y);
}