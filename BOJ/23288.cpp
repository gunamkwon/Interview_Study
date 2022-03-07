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

typedef struct {
	int y;
	int x;
	int dir;
}DICE;

int diceNum[7] = { 0, 1, 2, 3, 4, 5, 6 };
bool checked[21][21];
int N, M, K;
int diceMap[21][21];
DICE dice;
int result = 0;


// 동 남 서 북
int d_y[4] = { 0, 1, 0, -1 };
int d_x[4] = { 1, 0, -1, 0 };


int BFS(int num)
{
	int cnt = 1;
	memset(checked, false, sizeof(checked));
	vector<pair<int, int>> q;

	q.push_back(make_pair(dice.y, dice.x));
	checked[dice.y][dice.x] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.erase(q.begin());

		for (int i = 0; i < 4; i++) {
			int ny = cy + d_y[i];
			int nx = cx + d_x[i];

			if (ny > 0 && ny <= N && nx > 0 && nx <= M
				&& num == diceMap[ny][nx]
				&& !checked[ny][nx])
			{
				checked[ny][nx] = true;
				q.push_back(make_pair(ny, nx));
				cnt++;
			}
		}
	}

	return cnt;
}

int getScore()
{
	int score = diceMap[dice.y][dice.x];

	int cnt = BFS(score);

	score *= cnt;
	return score;
}

void diceMove(int dir)
{
	int nextNum[7] = { 0, };
	switch (dir) {
	case 0:		// 동쪽		
		nextNum[1] = diceNum[4];
		nextNum[2] = diceNum[2];
		nextNum[3] = diceNum[1];
		nextNum[4] = diceNum[6];
		nextNum[5] = diceNum[5];
		nextNum[6] = diceNum[3];
		break;
	case 1:		// 남쪽  
		nextNum[1] = diceNum[2];
		nextNum[2] = diceNum[6];
		nextNum[3] = diceNum[3];
		nextNum[4] = diceNum[4];
		nextNum[5] = diceNum[1];
		nextNum[6] = diceNum[5];
		break;
	case 2:		// 서쪽  
		nextNum[1] = diceNum[3];
		nextNum[2] = diceNum[2];
		nextNum[3] = diceNum[6];
		nextNum[4] = diceNum[1];
		nextNum[5] = diceNum[5];
		nextNum[6] = diceNum[4];
		break;
	case 3:		// 북
		nextNum[1] = diceNum[5];
		nextNum[2] = diceNum[1];
		nextNum[3] = diceNum[3];
		nextNum[4] = diceNum[4];
		nextNum[5] = diceNum[6];
		nextNum[6] = diceNum[2];
		break;
	}

	for (int i = 1; i <= 6; i++) {
		diceNum[i] = nextNum[i];
	}
}


int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> diceMap[i][j];
		}
	}

	dice.y = 1;
	dice.x = 1;
	dice.dir = 0;

	for (int i = 0; i < K; i++) {
		// 1. 주사위 이동 (위치, 밑면)
		// 위치 이동
		int ny = dice.y + d_y[dice.dir];
		int nx = dice.x + d_x[dice.dir];

		if (ny <= 0 || ny > N || nx <= 0 || nx > M) {
			dice.dir = (dice.dir + 2 >= 4) ? (dice.dir + 2) - 4 : dice.dir + 2;
			dice.y += d_y[dice.dir];
			dice.x += d_x[dice.dir];
		}
		else {
			dice.y = ny;
			dice.x = nx;
		}
		// 밑면 이동
		diceMove(dice.dir);

		// 2. 점수 획득
		result += getScore();

		// 3. 다음 방향 결정
		if (diceMap[dice.y][dice.x] < diceNum[6]) {	// A > B
			dice.dir = (dice.dir + 1 >= 4) ? (dice.dir + 1) - 4 : dice.dir + 1;
		}

		else if (diceMap[dice.y][dice.x] > diceNum[6]) { // A < B
			dice.dir = (dice.dir - 1 < 0) ? (dice.dir - 1) + 4 : dice.dir - 1;
		}
		else
			dice.dir = dice.dir;

	}

	cout << result;
}