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

int min(int a, int b) { return (a < b) ? a : b; }

int Map[11][31];
int N, M, H;
int answer = 4;

int checkEnd(int start)
{
	int pos = start;
	for (int level = 1; level <= H; level++) {
		if (Map[pos][level] == true) {
			pos += 1;
		}
		else if (Map[pos - 1][level] == true) {
			pos -= 1;
		}
	}

	return pos;
}

bool checkMap()
{
	for (int i = 1; i <= N; i++) {
		if (checkEnd(i) != i)
			return false;
	}
	return true;
}

void DFS(int idx, int cnt)
{
	if (cnt > 3) return;
	if (checkMap()) {
		answer = min(answer, cnt);
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (Map[j][i] == true) continue;
			if (Map[j - 1][i] == true) continue;
			if (Map[j + 1][i] == true) continue;

			Map[j][i] = true;
			DFS(i, cnt + 1);
			Map[j][i] = false;
		}
	}
}

void init()
{
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Map[b][a] = true;
	}
}

void solution()
{
	DFS(1, 0);
	if (answer == 4) cout << -1;
	else cout << answer;
}

int main()
{
	init();
	solution();
}