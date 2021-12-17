#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
#define INF 9999999

int n,m;
int map[101][101];

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if(map[a-1][b-1] > c)
			map[a-1][b-1] = c;
		
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i==j || map[i][j] == INF) printf("0 ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}