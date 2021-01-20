\#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int death_num(int n)
{
	while (n != 0) {
		if (n % 10 == 6) {
			if ((n / 10) % 10 == 6) {
				if ((n / 100) % 10 == 6) {
					return 1;
				}
				else n /= 10;
			}
			else n /= 10;
		}
		else n /= 10;
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	int series = 1;
	int name = 666;
	while (series != N) {
		name++;
		if (death_num(name) == 1)	series++;
	}
	printf("%d", name); return 0;
}

/*
#include<stdio.h>

int  process(int index, int number)
{
	int tmp;
	int count;
	int i;
	int ret;

	tmp = number;
	count = 0;
	while (tmp != 0)
	{
		if (tmp % 10 == 6)
		{
			count++;
			if (count == 3)
			{
				int base = 1;
				for (i = 0; i < index; i++)
					base = base * 10;

				return base;
			}
		}
		else
		{
			break;
		}
		tmp = tmp / 10;
	}
	if (index == 3 && count == 0)
		return 1;
	if (index == 3 && count == 1)
		return 10;
	if (index == 3 && count == 2)
		return 100;
	ret = 0;

	for (i = 0; i < 10; i++)
	{
		ret += process(index - 1, number * 10 + i);
	}
	return ret;
}


int find(int index, int number, int remain)
{
	int sum;
	int ret;
	int i;
	int base;
	int tmp;
	int count;

	tmp = number;
	count = 0; // 숫자 6 연속 count

	while (tmp != 0)
	{
		if (tmp % 10 == 6)
		{
			count++;
			if (count == 3)
			{
				int base = 1;

				for (i = 0; i < index; i++)
					base = base * 10;

				return number*base + remain-1;
			}
		}
		else	break;

		tmp = tmp / 10;
	}
	// count에 따라 값 다르게 출력
	if (index == 3 && count == 0)
	{
		return number * 1000 + 666;
	}
	if (index == 3 && count == 1)
	{
		return number * 1000 + 660 + remain-1;
	}
	if (index == 3 && count == 2)
	{
		return number * 1000 + 600 + remain-1;
	}

	sum = 0;
	for (i = 0; i < 10; i++)
	{
		ret = process(index - 1, number * 10 + i);

		if (sum + ret >= remain)
			break;
		else
			sum = sum + ret;
	}
	return find(index - 1, number * 10 + i, remain - sum);
}

int main()
{
	int N;
	scanf("%d\n", &N);
	printf("%d\n", find(7, 0, N));
	return 0;
}
*/