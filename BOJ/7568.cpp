#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}BODY;

int main()
{
	int N, i;
	scanf("%d", &N);
	BODY* body = (BODY*)malloc(sizeof(BODY) * N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &body[i].x, &body[i].y);
	}
	int* rank = (int*)malloc(sizeof(rank) * N);


	for (i = 0; i < N; i++) {
		rank[i] = 1;
		for (int j = 0; j < N; j++) {
			if (body[i].x < body[j].x && body[i].y < body[j].y)
				rank[i]++;
		}
		printf("%d ", rank[i]);
	}
}