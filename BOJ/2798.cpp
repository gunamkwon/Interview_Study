#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;

int find(int* card)
{
	int result = 0;
	if (result == M) return result;
	int i,j,k;
	int sub = 0;
	for (i = 0; i < (N - 2); i++) {
		for (j = i + 1; j < (N - 1); j++) {
			for (k = j + 1; k < N; k++) {
				int total = card[i] + card[j] + card[k];
				if (total <= M && M - total < M - result) {
					result = total;
				}
			}
		}
	}
	return result;
}

int main()
{
	scanf("%d %d", &N, &M);

	int card[100];
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	int result = find(card);
	printf("%d", result);
}