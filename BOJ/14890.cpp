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

int N, L;
int road[101][101];
bool checkRoad[101][101];

int result = 0;

bool checkMap(int i, int dir)
{
	memset(checkRoad, false, sizeof(checkRoad));
	if (dir == 0) {
		int height = road[i][0];
		for (int j = 1; j < N; j++) {
			int cur_height = road[i][j];
			if (cur_height == height) continue;
			else {
				return false;
			}
		}

		return true;
	}
	else {
		int height = road[0][i];
		for (int j = 1; j < N; j++) {
			int cur_height = road[j][i];
			if (cur_height == height) continue;
			else {
				return false;
			}
		}

		return true;
	}
}

bool checkMapWithBar(int i, int dir)
{
	memset(checkRoad, false, sizeof(checkRoad));
	int withoutBar = 0;
	if (dir == 0) {
		int height = road[i][0];
		for (int j = 1; j < N; j++) {
			int cur_height = road[i][j];
			if (cur_height == height) continue;
			else {
				if (abs(cur_height - height) > 1 || checkRoad[i][j]) return false;
				if (cur_height > height) {		// ������ ����
					if (j < L) return false;
					for (int k = L; k > 0; k--) {		// ���� ���� ������ Ȯ��
						if (checkRoad[i][j - k] || height != road[i][j - k]) return false;
					}
					for (int k = L; k > 0; k--) {
						withoutBar = 1;
						checkRoad[i][j - k] = true;
					}
					height = cur_height;
				}
				else {		// ������ ����
					if (N - j < L) return false;
					for (int k = 0; k < L; k++) {		// ���� ���� ������ Ȯ��
						if (cur_height != road[i][j + k] || checkRoad[i][j + k]) return false;
					}
					for (int k = 0; k < L; k++) {		// ���� ���� ����
						withoutBar = 1;
						checkRoad[i][j + k] = true;
					}
					height = cur_height;
				}
			}
		}

		if (withoutBar != 0)
			return true;
		else return false;
	}

	else {
		int height = road[0][i];
		for (int j = 1; j < N; j++) {
			int cur_height = road[j][i];
			if (cur_height == height) continue;
			else {
				if (abs(cur_height - height) > 1 || checkRoad[j][i]) return false;
				if (cur_height > height) {		// ������ ����
					if (j < L) return false;
					for (int k = L; k > 0; k--) {		// L�� ����??
						if (height != road[j - k][i] || checkRoad[j - k][i]) return false;
					}
					for (int k = L; k > 0; k--) {
						withoutBar = 1;
						checkRoad[j - k][i] = true;
					}
					height = cur_height;
				}
				else {		// ������ ����
					if (N - j < L) return false;
					for (int k = 0; k < L; k++) {		// ���� ���� ������, ���� �ִ��� Ȯ��
						if (cur_height != road[j + k][i] || checkRoad[j + k][i]) return false;
					}
					for (int k = 0; k < L; k++) {
						withoutBar = 1;
						checkRoad[j + k][i] = true;
					}
					height = cur_height;
				}
			}
		}


		if (withoutBar != 0)
			return true;
		else return false;
	}
}

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> road[i][j];
		}
	}

	// ���� ���� ��
	// 0 - ���� 
	// 1 - ����
	for (int i = 0; i < N; i++) {
		if (checkMap(i, 0)) result++;
		if (checkMap(i, 1)) result++;
	}

	for (int i = 0; i < N; i++) {
		if (checkMapWithBar(i, 0)) result++;
		if (checkMapWithBar(i, 1)) result++;
	}

	cout << result;
}