#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 99999999

int N, M, X;
vector<pair<int, int>> road[1001];
int dis[1001];
vector<int> answer(1001,0);

void dijkstra(int start)
{
	// 초기화 작업
	for (int i = 1; i <= N; i++) {
		dis[i] = INF;
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curTime = -pq.top().first;
		pq.pop();

		if (curTime > dis[cur])
			continue;

		for (int i = 0; i < road[cur].size(); i++) {
			int next = road[cur][i].first;
			int nextTime = road[cur][i].second;
			
			if (dis[next] > curTime + nextTime) {
				dis[next] = curTime + nextTime;
				pq.push(make_pair(-dis[next], next));
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int from, to, time;
		cin >> from >> to >> time;

		road[from].push_back(make_pair(to, time));
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		dijkstra(i);
		answer[i] += dis[X];
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		answer[i] += dis[i];
		res = max(res, answer[i]);
	}

	cout << res;
}