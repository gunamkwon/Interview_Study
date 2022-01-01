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


int max(int a, int b) { return (a > b) ? a : b; }

typedef struct {
	int y, x, dir, live;
}Fish;


int Map[4][4];
Fish fish[20];

int d_y[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int d_x[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int answer;

void copyState(int mapFrom[][4], int mapTo[][4], Fish fishFrom[], Fish fishTo[])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mapTo[i][j] = mapFrom[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		fishTo[i] = fishFrom[i];
	}
}

void swapFish(int idx, int sIdx)
{
	Fish temp = fish[sIdx];
	fish[sIdx].y = fish[idx].y;
	fish[sIdx].x = fish[idx].x;

	fish[idx].y = temp.y;
	fish[idx].x = temp.x;
}

void moveFish()
{
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live == false) continue;

		int cy = fish[i].y;
		int cx = fish[i].x;
		int cdir = fish[i].dir;

		int ny = cy + d_y[cdir];
		int nx = cx + d_x[cdir];
		bool flag = false;

		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			if (Map[ny][nx] == 0)
			{
				flag = true;
				Map[ny][nx] = i;
				Map[cy][cx] = 0;

				fish[i].y = ny;
				fish[i].x = nx;
			}
			else if (Map[ny][nx] != -1) {
				flag = true;
				swapFish(i, Map[ny][nx]);
				swap(Map[cy][cx], Map[ny][nx]);
			}
		}

		if (flag == false)
		{
			int ndir = (cdir + 1 > 8) ? 1 : cdir + 1;

			while (cdir != ndir)
			{
				int ny = cy + d_y[ndir];
				int nx = cx + d_x[ndir];

				if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
					if (Map[ny][nx] == 0)
					{
						Map[ny][nx] = i;
						Map[cy][cx] = 0;

						fish[i].y = ny;
						fish[i].x = nx;
						fish[i].dir = ndir;
						break;
					}

					else if (Map[ny][nx] != -1)
					{
						swapFish(i, Map[ny][nx]);
						swap(Map[ny][nx], Map[cy][cx]);
						fish[i].dir = ndir;
						break;
					}
				}
				ndir = (ndir + 1 > 8) ? 1 : ndir + 1;
			}
		}
	}
}

void makeState(int y, int x, int ny, int nx, int fishNum, bool T)
{
	if (T == true)
	{
		Map[y][x] = 0;
		Map[ny][nx] = -1;
		fish[fishNum].live = false;
	}
	else
	{
		Map[y][x] = -1;
		Map[ny][nx] = fishNum;
		fish[fishNum].live = true;
	}
}

void DFS(int y, int x, int dir, int sum)
{
	answer = max(answer, sum);

	int cMap[4][4];
	Fish cFish[20];
	copyState(Map, cMap, fish, cFish);
	moveFish();

	for (int i = 1; i <= 3; i++) {
		int ny = y + d_y[dir] * i;
		int nx = x + d_x[dir] * i;

		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			if (Map[ny][nx] == 0) continue;

			int fishNum = Map[ny][nx];
			int nDir = fish[fishNum].dir;

			makeState(y, x, ny, nx, fishNum, true);
			DFS(ny, nx, nDir, sum + fishNum);
			makeState(y, x, ny, nx, fishNum, false);
		}
		else break;
	}

	copyState(cMap, Map, cFish, fish);
}

void init()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			Map[i][j] = a;

			fish[a] = { i,j,b,true };
		}
	}
}

void solution()
{
	// 초기 설정
	int fishNum = Map[0][0];
	int dir = fish[fishNum].dir;
	fish[fishNum].live = false;
	Map[0][0] = -1;


	// DFS
	DFS(0, 0, dir, fishNum);

	cout << answer;
}

int main()
{
	init();
	solution();
}