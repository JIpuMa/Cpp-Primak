//Hw1 �0.0.5b
/*�����:
 ������� �� ����� �����:
 �) a----------a
	|      a      |
	a----------a
�� a � ������� � ��������� �����.
*/

#include <stdio.h>

int main()
{
	int a;
	printf("a=");
	scanf_s("%d", &a);
	printf("%d----------%d\n", a, a);
	printf("|     %d     |\n", a);
	printf("%d----------%d\n", a, a);
}