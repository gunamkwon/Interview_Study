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

int N, K;

int fishHome[101];
int tempFish[101][101];
int moveFish[101][101];

int result;

int d_y[4] = { 1, 0 };
int d_x[4] = { 0, 1 };


bool difFish()
{
	int max = 0;
	int min = 10000000;

	for (int i = 1; i <= N; i++) {
		max = (fishHome[i] > max) ? fishHome[i] : max;
		min = (fishHome[i] < min) ? fishHome[i] : min;
	}

	if (max - min > K) return false;
	else return true;
}

void step1()
{
	for (int i = 2; i <= N; i++) {
		tempFish[0][i] = fishHome[i];
	}
	tempFish[1][2] = fishHome[1];

	int size = 2;
	int width = 1;
	int idx = 3;
	bool oddeven = false;

	while (idx + (size - 1) <= N) {

		int curIdx = idx;
		for (int j = 0; j < size; j++) {
			int pos = 1;
			for (int i = idx - 1; i >= idx - width; i--) {
				tempFish[pos++][curIdx] = tempFish[j][i];
				tempFish[j][i] = 0;
			}
			curIdx++;
		}

		idx += size;	// 다음 idx
		size = width + 1;
		if (oddeven) {
			oddeven = false;
		}
		else {
			oddeven = true;
			width = size;
		}

	}

}

void step2()
{
	for (int i = N / 2 + 1; i <= N; i++) {
		tempFish[0][i] = fishHome[i];
	}

	for (int i = 1; i <= N / 2; i++) {
		tempFish[1][N - (i - 1)] = fishHome[i];
	}

	int size = N / 2;
	int start = (N / 2 + 1) + size / 2;

	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= size / 2; i++) {
			tempFish[j + 2][start + (i - 1)] = tempFish[1 - j][start - i];
			tempFish[1 - j][start - i] = 0;
		}
	}
}

void movingFish()
{
	memset(moveFish, 0, sizeof(moveFish));

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (tempFish[i][j] != 0) {
				for (int dir = 0; dir < 2; dir++) {
					int ny = i + d_y[dir];
					int nx = j + d_x[dir];

					if (ny >= 0 && ny <= N && nx >= 0 && nx <= N && tempFish[ny][nx] != 0) {
						if (tempFish[i][j] > tempFish[ny][nx]) {
							int d = (tempFish[i][j] - tempFish[ny][nx]) / 5;
							if (d > 0) {
								moveFish[i][j] -= d;
								moveFish[ny][nx] += d;
							}
						}
						else {
							int d = (tempFish[ny][nx] - tempFish[i][j]) / 5;
							if (d > 0) {
								moveFish[i][j] += d;
								moveFish[ny][nx] -= d;
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			tempFish[i][j] += moveFish[i][j];
		}
	}
}

void movetoArray()
{
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		if (tempFish[0][i] != 0) {
			int j = 0;
			while (tempFish[j][i] != 0) {
				fishHome[idx++] = tempFish[j++][i];
			}
		}
	}
}

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> fishHome[i];
	}

	while (1) {

		// 물고기 추가
		int min = 1000000;
		for (int i = 1; i <= N; i++) {
			min = (fishHome[i] < min) ? fishHome[i] : min;
		}
		for (int i = 1; i <= N; i++) {
			if (fishHome[i] == min) fishHome[i]++;
		}


		// 어항 쌓기 1단계
		memset(tempFish, 0, sizeof(tempFish));

		step1();
		// 물고기 수 조절
		movingFish();
		// 일렬로 놓기
		movetoArray();


		//어항 쌓기 2단계
		memset(tempFish, 0, sizeof(tempFish));
		step2();
		// 물고기 수 조절
		movingFish();
		// 일렬로 놓기
		movetoArray();


		// 정리 완료
		result++;
		if (difFish()) break;
	}


	cout << result;
}