#include <stdio.h>
#include <cmath>

int main()
{
	double a, b, c;
	printf("a = ");
	scanf_s("%lf", &a);
	printf("b = ");
	scanf_s("%lf", &b);
	printf("c = ");
	scanf_s("%lf", &c);
	
	double max, mid, min;

	if (a < b)
	{
		if (a < c)
		{
			min = a;
			if (b < c)
			{
				max = c;
				mid = b;
			}
			else
			{
				max = b;
				mid = c;
			}
		}
		else
		{
			min = c;
			mid = a;
			max = b;
		}
	}
	else
	{
		if (b < c)
		{
			min = b;
			if (a < c)
			{
				max = c;
				mid = a;
			}
			else
			{
				max = a;
				mid = c;
			}
		}
		else
		{
			min = c;
			mid = b;
			max = a;
		}
	}

	if ((max >= mid + min) || (min <= max - mid))
	{
		printf("Tringle does not exist");
	}
	else if (pow(max, 2) < pow(mid, 2) + pow(min, 2))
	{
		printf("Acute-angled triangle");
	}
	else if (pow(max, 2) == pow(mid, 2) + pow(min, 2))
	{
		printf("Rectangular triangle");
	}
	else if (pow(max, 2) > pow(mid, 2) + pow(min, 2))
	{
		printf("Obtuse-angled triangle");
	}
}