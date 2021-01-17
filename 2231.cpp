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
- 좀 더 생각해보면 분해합 N이 만들어 질 수 있는 생성자의 최대 자릿수는 6자릿수

  (생성자가 1,000,000 이면 분해합은 1,000,001 이므로 7 자릿수는 나올 수 없음)

  각 자릿수의 최대 값은 9

  즉, 생성자는 분해합 보다 54 이상 작을 수 없음.

  N-54 부터 N-1 까지만 찾으면 됨.

  가장 작은 수 부터 찾을 거니 처음 만나는 생성자가 최소값
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