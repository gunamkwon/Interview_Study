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


/// <summary>
/// 맵으로 중복되는 애들 한번에 관리해야 함
/// </summary>
typedef struct {
	int y;
	int x;
	int dir;
}FISH;


typedef struct {
	int y;
	int x;
}Shark;

int M, S, T, result;
int maxDead;

int scentMap[5][5];
Shark shark;
vector<FISH> fish;
vector<int> maxMove;


int d_y[9] = { 0, 0, -1, -1, -1, 0 , 1, 1, 1 };
int d_x[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int s_y[4] = { -1, 0, 1, 0 };
int s_x[4] = { 0, -1, 0, 1 };

void movingFish()
{
	for (int i = 0; i < fish.size(); i++) {
		int cy = fish[i].y;
		int cx = fish[i].x;
		int dir = fish[i].dir;

		for (int d = 0; d < 8; d++) {
			int ndir = (dir - d <= 0) ? dir - d + 8 : dir - d;
			int ny = cy + d_y[ndir];
			int nx = cx + d_x[ndir];

			if ((ny > 0 && ny <= 4 && nx > 0 && nx <= 4)	// 맵 안
				&& !(ny == shark.y && nx == shark.x)		// 상어 칸 X 
				&& scentMap[ny][nx] == 0)					// 향기 없는 칸
			{
				fish[i].y = ny;
				fish[i].x = nx;
				fish[i].dir = ndir;
				break;
			}
		}
	}
}

int countFish(vector<int> sharkMove)
{
	int cnt = 0;
	vector<FISH> copyFish = fish;
	Shark copyShark = shark;
	vector<bool> check(fish.size(), 0);

	for (int i = 0; i < 3; i++) {
		copyShark.y += s_y[sharkMove[i]];
		copyShark.x += s_x[sharkMove[i]];

		if (copyShark.y <= 0 || copyShark.x <= 0 || copyShark.y > 4 || copyShark.x > 4) return -1;
		int s;
		for (s = 0; s < fish.size(); s++) {
			if (fish[s].y == copyShark.y && fish[s].x == copyShark.x) {
				if (!check[s]) {
					check[s] = true;
					cnt++;
				}

			}

		}
	}

	return cnt;
}

void maxMovingShark(vector<int> sharkMove, int time)
{
	vector<FISH> copyFish = fish;

	for (int i = 0; i < 3; i++) {
		shark.y += s_y[sharkMove[i]];
		shark.x += s_x[sharkMove[i]];

		for (int s = 0; s < fish.size(); s++) {
			if (fish[s].y == shark.y && fish[s].x == shark.x) {
				copyFish[s].y = 0;
				scentMap[fish[s].y][fish[s].x] = 3;
			}

		}
	}

	fish.clear();
	for (int i = 0; i < copyFish.size(); i++) {
		if (copyFish[i].y == 0) continue;
		fish.push_back(copyFish[i]);
	}

}

void movingShark(int cnt, vector<int> sharkMove)
{
	if (cnt == 3) {
		int dead = countFish(sharkMove);
		if (maxDead < dead) {
			maxDead = dead;
			maxMove = sharkMove;
		}

		else if (maxDead == dead) {
			if (maxMove.empty())
				maxMove = sharkMove;
			//else {
			//	int a = 0, b = 0;
			//	int mul = 100;
			//	for (int i = 0; i < 3; i++, mul/=10) {
			//		a += maxMove[i] * mul;
			//		b += sharkMove[i] * mul;						
			//	}
			//	if (a > b)
			//		maxMove = sharkMove;
			//}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		sharkMove.push_back(i);
		movingShark(cnt + 1, sharkMove);
		sharkMove.erase(sharkMove.end() - 1);
	}
}


int main()
{
	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		fish.push_back({ x,y,d });
	}

	cin >> shark.y >> shark.x;


	for (int T = 0; T < S; T++) {
		// 1. 복제 마법 준비
		vector<FISH> copyFish;
		for (int i = 0; i < fish.size(); i++) {
			copyFish.push_back(fish[i]);
		}

		// 2. 물고기 이동
		movingFish();

		// 3. 상어 이동
		maxMove.clear();
		maxDead = 0;
		vector<int>sharkMove;
		movingShark(0, sharkMove);
		maxMovingShark(maxMove, T);


		// 4. 냄새 리스트 확인
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (scentMap[i][j] > 0)
					scentMap[i][j]--;
			}
		}

		// 5. 복제 마법 ON
		for (int i = 0; i < copyFish.size(); i++) {
			fish.push_back(copyFish[i]);
		}
	}

	result = fish.size();
	cout << result;
}