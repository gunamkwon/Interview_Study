#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 99999999


struct Node {
	int cost;
	int y;
	int x;	
};

struct compare {
	bool operator()(const Node& a,const Node& b)
	{
		return a.cost < b.cost;
	}
};

int N;

int map[126][126] = { 0, };
int dis[126][126] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };



int Dijkstra(int sy, int sx)
{
	priority_queue<Node,vector<Node>,compare> pq;
	//priority_queue<Node> pq;
	int weight = map[sy][sx];
	
	pq.push({ -weight, sy, sx });
	dis[sy][sx] = weight;

	while (!pq.empty()) {
		int curCost = -pq.top().cost;
		int curY = pq.top().y;
		int curX = pq.top().x;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
				int nextCost = map[nextY][nextX];

				if (dis[nextY][nextX] > curCost + nextCost) {
					dis[nextY][nextX] = curCost + nextCost;
					pq.push({ -dis[nextY][nextX], nextY, nextX });
				}
			}			
		}
	}
	
	return dis[N - 1][N - 1];
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dis[i][j] = INF;
			}
		}

		int n = Dijkstra(0, 0);

		cout << "Problem " << ++cnt << ": " << n << '\n';
	}
	
}