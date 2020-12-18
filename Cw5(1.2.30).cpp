#include <stdio.h>

int main()
{
	int F1 = 1, F2 = 1;
	int Fk, f, i, n;
	printf("n=");
	scanf_s("%d", &n);
	if (n == 1) {
		Fk = F1;
	}
	else {
		if (n == 2) {
			Fk = F2;
		}
		else {
			i = 3;
			while (i <= n) {
				f = F2;
				F2 = F1 + F2;
				F1 = f;
				i++;
			}
			Fk = F2;
		}
	}
	printf("Fk=%d", Fk);
}