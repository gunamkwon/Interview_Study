#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int constructor(int N)
{
	int M=0;
	if (N > 0 && N < 10) {
		for (M = 0; M < N; M++)
			if (M + M == N) return M;
	}
	else if (N >= 10 && N < 100) {
		for (M = 0; M < 10; M++)
			if (M + M == N) return M;
		for (; M < N; M++)
			if (M + M / 10 + M % 10 == N) return M;
	}
	else if (N >= 100 && N < 1000) {
		for (M = 10; M < 100; M++)
			if (M + M % 10 + M / 10 == N) return M;
		for (; M < N; M++)
			if (M + M %10 + (M / 10) % 10 + (M / 100) % 10 == N) return M;
	}
	else if (N >= 1000 && N < 10000) {
		for (M = 100; M < 1000; M++)
			if (M + M % 10 + (M / 10) % 10 + (M / 100) % 10 == N) return M;
		for (M = 1000; M < N; M++)
			if (M + M %10 + (M / 10) % 10 + (M / 100) % 10 + (M / 1000) % 10 == N) return M;
	}
	else if (N >= 10000 && N < 100000) {
		for (M = 1000; M < 10000; M++)
			if (M + M % 10 + (M / 10) % 10 + (M / 100) % 10 + (M / 1000) % 10 == N) return M;
		for (; M < N; M++)
			if (M + M % 10 + (M / 10) % 10 + (M / 100) % 10 + (M / 1000) % 10 + (M/10000) %10 == N) return M;
	}
	else if (N >= 100000 && N < 1000000) {
		for (M = 10000; M < 100000; M++)
			if (M + M % 10 + (M / 10) % 10 + (M / 100) % 10 + (M / 1000) % 10 + (M / 10000) % 10 == N) return M;
		for (; M < N; M++)
			if (M + M % 10 + (M / 10) % 10 + (M / 100) % 10 + (M / 1000) % 10 + (M / 10000) % 10 + (M/100000) % 10 == N) return M;
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	int result = constructor(N);
	printf("%d", result);
}

/*
- �� �� �����غ��� ������ N�� ����� �� �� �ִ� �������� �ִ� �ڸ����� 6�ڸ���

  (�����ڰ� 1,000,000 �̸� �������� 1,000,001 �̹Ƿ� 7 �ڸ����� ���� �� ����)

  �� �ڸ����� �ִ� ���� 9

  ��, �����ڴ� ������ ���� 54 �̻� ���� �� ����.

  N-54 ���� N-1 ������ ã���� ��.

  ���� ���� �� ���� ã�� �Ŵ� ó�� ������ �����ڰ� �ּҰ�
#include <stdio.h>

int main() {

	int N, i;
	int flag = 0;

	scanf("%d", &N);

	for (i = N-54; i <= N; i++) {
		int sum = i;
		for (int j = 1; j <= 1000000; j*=10) {
			sum += (i/j)%10;
			if (i/j==0)  break;
		}
		if (sum == N) {
			flag = 1;
			break;
		}
	}

	flag == 1 ? printf("%d", i) : printf("0");

	return 0;
}
*/