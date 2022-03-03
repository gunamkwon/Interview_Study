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

int N, M;
int block[21][21];
bool checkMap[21][21];

int d_y[4] = { 0,1,0,-1 };
int d_x[4] = { 1,0,-1,0 };

typedef struct {
	int y;
	int x;
	int size;
	int rainbow_cnt;
	vector<pair<int, int>> pos;
}Group;

vector<Group> group;
int result = 0;

Group BFS(Group g, int num)
{
	for (int i1 = 1; i1 <= N; i1++) {
		for (int j1 = 1; j1 <= N; j1++) {
			if (block[i1][j1] == 0)
				checkMap[i1][j1] = false;
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(g.y, g.x));
	checkMap[g.y][g.x] = true;

	while (!q.empty()) {
		int cY = q.front().first;
		int cX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nY = cY + d_y[i];
			int nX = cX + d_x[i];

			if (nY <= 0 || nY > N || nX <= 0 || nX > N || block[nY][nX] == -1) continue;
			if (!checkMap[nY][nX] && (block[nY][nX] == num || block[nY][nX] == 0)) {
				checkMap[nY][nX] = true;
				q.push(make_pair(nY, nX));

				if (block[nY][nX] == 0)
					g.rainbow_cnt++;
				g.size++;
				g.pos.push_back(make_pair(nY, nX));
			}
		}
	}

	return g;
}

Group compareMax(Group max, Group g)
{
	if (max.size > g.size)
		return max;
	else if (max.size < g.size)
		return g;
	else {
		if (max.rainbow_cnt > g.rainbow_cnt)
			return max;
		else if (max.rainbow_cnt < g.rainbow_cnt)
			return g;
		else {
			if (max.y > g.y)
				return max;
			else if (max.y < g.y)
				return g;
			else {
				if (max.x > g.x)
					return max;
				else
					return g;
			}
		}
	}
}

void gravity()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (block[i][j] == -100) {
				int ny = i - 1;
				int cy = i;
				while (ny > 0 && block[ny][j] != -1) {
					block[cy][j] = block[ny][j];
					block[ny][j] = -100;
					cy--; ny--;
				}
			}
		}
	}
}

void rotateBlock()
{
	int temp[21][21];

	int tx, ty, bx, by;
	for (tx = 1, bx = N; tx <= N; ++tx, --bx) {
		for (ty = 1, by = 1; ty <= N; ++ty, ++by) {
			temp[tx][ty] = block[by][bx];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			block[i][j] = temp[i][j];
		}
	}
}


int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> block[i][j];
		}
	}

	while (1) {
		// 1번
		memset(checkMap, false, sizeof(checkMap));
		Group max;
		max.size = -1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (block[i][j] > 0) {
					Group g;
					g.y = i; g.x = j; g.size = 1; g.rainbow_cnt = 0;
					g.pos.push_back(make_pair(i, j));
					g = BFS(g, block[i][j]);
					if (g.size >= 2)
						max = compareMax(max, g);
				}
			}
		}

		// 블록 없으면 STOP
		if (max.size == -1) break;

		// 2번
		result += max.size * max.size;

		for (int i = 0; i < max.pos.size(); i++) {
			pair<int, int> erase = max.pos[i];
			block[erase.first][erase.second] = -100;
		}

		// 3. 중력 작용
		gravity();
		// 4. 회전
		rotateBlock();
		// 5. 중력 작용
		gravity();
	}


	cout << result;
}