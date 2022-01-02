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

#define MAX 11
typedef struct {
	int r;
	int c;
	int age;
}Tree;

int N, M, K;
int Map[MAX][MAX];
int A[MAX][MAX];

deque<Tree> liveTree, deadTree;
int d_r[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int d_c[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };


void spring()
{
	for (int i = 0; i < liveTree.size(); i++) {
		int r = liveTree[i].r;
		int c = liveTree[i].c;
		int age = liveTree[i].age;

		if (Map[r][c] - age >= 0) {
			Map[r][c] -= age;
			liveTree[i].age += 1;
		}
		else {
			deadTree.push_back(liveTree[i]);
			liveTree.erase(liveTree.begin() + i);
			i--;
		}
	}
}

void summer()
{
	for (int i = 0; i < deadTree.size(); i++) {
		int r = deadTree[i].r;
		int c = deadTree[i].c;

		Map[r][c] += deadTree[i].age / 2;
	}

	deadTree.clear(); deadTree.resize(0);
}

void fall()
{
	deque<Tree> cLiveTree;
	cLiveTree = liveTree;
	for (int i = 0; i < liveTree.size(); i++) {
		if (liveTree[i].age % 5 == 0) {
			int r = liveTree[i].r;
			int c = liveTree[i].c;

			for (int d = 0; d < 8; d++) {
				int nr = r + d_r[d];
				int nc = c + d_c[d];

				if (nr > 0 && nr <= N && nc > 0 && nc <= N) {
					cLiveTree.push_front({ nr, nc, 1 });
				}
			}
		}
	}

	liveTree = cLiveTree;
}

void winter()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Map[i][j] += A[i][j];
		}
	}
}


bool cmp(Tree& a, Tree& b)
{
	return a.age < b.age;
}

void solution()
{
	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << liveTree.size() << endl;
}

void init()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			Map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		liveTree.push_back({ x,y,z });
	}

	sort(liveTree.begin(), liveTree.end(), cmp);
}

int main()
{
	init();
	solution();
}

