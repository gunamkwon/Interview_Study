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

struct Node
{
	int r, c, num;
};

int N, M;
int answer = 100;
vector<vector<int>> office(8, vector<int>(8));
vector<Node> camera;

int getBlindSpots(vector<vector<int>> office)
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (office[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

vector<vector<int>> setWatchSpots(vector<vector<int>> temp, int d, int r, int c)
{
	// 合率
	if (d == 0) {
		for (int i = r; i >= 0; i--) {
			if (temp[i][c] == 6) break;
			else if (temp[i][c] == 0) {
				temp[i][c] = -1;
			}
		}
	}

	// 悼率
	if (d == 1) {
		for (int i = c; i < M; i++) {
			if (temp[r][i] == 6) break;
			else if (temp[r][i] == 0) {
				temp[r][i] = -1;
			}
		}
	}

	// 巢率
	if (d == 2) {
		for (int i = r; i < N; i++) {
			if (temp[i][c] == 6) break;
			else if (temp[i][c] == 0) {
				temp[i][c] = -1;
			}
		}
	}

	// 辑率
	if (d == 3) {
		for (int i = c; i >= 0; i--) {
			if (temp[r][i] == 6) break;
			else if (temp[r][i] == 0) {
				temp[r][i] = -1;
			}
		}
	}

	return temp;
}

void dfs(int L, vector<vector<int>> office)
{
	if (L == camera.size()) {
		answer = min(answer, getBlindSpots(office));
		return;
	}

	vector<vector<int>> temp;

	if (camera[L].num == 1) {
		for (int i = 0; i < 4; i++) {
			dfs(L + 1, setWatchSpots(office, i, camera[L].r, camera[L].c));
		}
	}

	else if (camera[L].num == 2) {
		temp = setWatchSpots(office, 0, camera[L].r, camera[L].c);
		temp = setWatchSpots(temp, 2, camera[L].r, camera[L].c);
		dfs(L + 1, temp);
		temp = setWatchSpots(office, 1, camera[L].r, camera[L].c);
		temp = setWatchSpots(temp, 3, camera[L].r, camera[L].c);
		dfs(L + 1, temp);
	}

	else if (camera[L].num == 3) {
		for (int i = 0; i < 4; i++) {
			temp = office;
			if (i == 3) {
				temp = setWatchSpots(temp, 0, camera[L].r, camera[L].c);
				temp = setWatchSpots(temp, 3, camera[L].r, camera[L].c);
				dfs(L + 1, temp);
			}
			else {
				temp = setWatchSpots(temp, i, camera[L].r, camera[L].c);
				temp = setWatchSpots(temp, i + 1, camera[L].r, camera[L].c);
				dfs(L + 1, temp);
			}
		}
	}

	else if (camera[L].num == 4) {
		for (int i = 0; i < 4; i++) {
			temp = office;
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				temp = setWatchSpots(temp, j, camera[L].r, camera[L].c);
			}
			dfs(L + 1, temp);
		}
	}

	else if (camera[L].num == 5) {
		temp = office;
		for (int i = 0; i < 4; i++)
			temp = setWatchSpots(temp, i, camera[L].r, camera[L].c);
		dfs(L + 1, temp);
	}
}

void solution()
{
	dfs(0, office);
	cout << answer;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5)
				camera.push_back({ i,j, office[i][j] });
		}
	}

	solution();
}