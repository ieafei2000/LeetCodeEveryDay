#include <iostream>

int divide(int a, int b)
{
	if (a == INT_MIN && b == -1)
	{
		return INT_MAX;
	}
	
	long int quotient = 0;
	long int aFabs = fabs(a);
	long int bFabs = fabs(b);

	int cnt = 1;

	while (aFabs - bFabs * pow(2, cnt) > 0)
	{
		cnt++;
	}
	cnt--;
	if (cnt != 0)
	{
		aFabs -= bFabs * pow(2, cnt);
	}

	std::cout << cnt << " " << aFabs << std::endl;

	while (aFabs - bFabs >= 0)
	{
		quotient++;
		aFabs -= bFabs;
	}
	if (cnt != 0)
	{
		quotient += pow(2, cnt);
	}

	if ((a >0 && b > 0) || (a < 0 && b < 0))
	{
		return quotient;
	}
	else
	{
		return -quotient;
	}
}

int main()
{
	std::cout << divide(1, 2) << std::endl;
}
