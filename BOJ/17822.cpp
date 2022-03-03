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

int N, M, T;
int target[51][51];

int result = 0;

void rotateTarget(int x, int d, int k)
{
	int _x = x;
	int dir;
	if (d == 0) dir = 1;
	else dir = -1;
	int i = 1;


	while (x <= N) {
		int temp[51] = { 0, };
		for (int m = 1; m <= M; m++) {
			int pos = m + k * dir;
			if (pos <= 0) pos += M;
			else if (pos > M) pos -= M;

			temp[pos] = target[x][m];
		}

		for (int m = 1; m <= M; m++) {
			target[x][m] = temp[m];
		}

		x = _x * (++i);
	}
}

void eraseTarget()
{
	int tempTarget[51][51] = { 0, };
	bool erased = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tempTarget[i][j] = target[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		bool erase[51] = { 0, };
		for (int j = 1; j <= M; j++) {
			if (tempTarget[i][j] == 0) continue;

			// 다음 원판 비교
			if (i == 1) {
				if (tempTarget[i][j] == target[2][j])
					erase[j] = true;
			}
			else if (i == N) {
				if (tempTarget[i][j] == target[N - 1][j])
					erase[j] = true;
			}
			else {
				if (tempTarget[i][j] == target[i - 1][j]
					|| tempTarget[i][j] == target[i + 1][j])
					erase[j] = true;
			}

			// 원판 내 비교
			if (j == 1) {
				if (tempTarget[i][j] == target[i][2] || tempTarget[i][j] == target[i][M])
					erase[j] = true;
			}
			else if (j == M) {
				if (tempTarget[i][j] == target[i][1] || tempTarget[i][j] == target[i][M - 1])
					erase[j] = true;
			}
			else {
				if (tempTarget[i][j] == target[i][j + 1] || tempTarget[i][j] == target[i][j - 1])
					erase[j] = true;
			}
		}

		for (int j = 1; j <= M; j++) {
			if (erase[j]) {
				erased = true;
				tempTarget[i][j] = 0;
			}
		}
	}

	if (!erased) {
		float avg = 0;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tempTarget[i][j] != 0) cnt++;
				avg += tempTarget[i][j];
			}
		}
		avg /= cnt;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tempTarget[i][j] == 0) continue;
				if (tempTarget[i][j] > avg)
					tempTarget[i][j]--;
				else if (tempTarget[i][j] < avg)
					tempTarget[i][j]++;
			}
		}

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			target[i][j] = tempTarget[i][j];
		}
	}
}

int main()
{
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> target[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;

		rotateTarget(x, d, k);
		eraseTarget();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			result += target[i][j];
		}
	}

	cout << result;
}