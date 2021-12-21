#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0,-1,-1,1,1,0 };
int dy[] = { 0,0,-1,1,1,-1,1,-1,0 };

string map[8];
queue<vector<int>> q;
int visit[8][8] = { 0 };

void moveDown() {
	for (int i = 0; i < 8; i++) {
		for (int j = 7; j > 0; j--)
			map[j][i] = map[j-1][i];
		map[0][i] = '.';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> map[i];

	int p = 1;
	q.push({ 7, 0, 1 });
	visit[7][0] = 1;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int c = q.front()[2];
		if (x == 0 && y == 7) break;
		q.pop();
		if (c != p) {
			moveDown();
			p = c;
		}
		if (map[x][y] == '#') continue;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || visit[nx][ny] == c + 1) continue;
			if (map[nx][ny] == '#') continue;
			q.push({ nx, ny, c + 1 });
			visit[nx][ny] = c + 1;
		}
	}
	printf("%d", q.empty() ? 0 : 1);
}