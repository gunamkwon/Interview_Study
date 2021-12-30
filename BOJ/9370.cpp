#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const long INF = 10000000000;
int N, E;
int v1, v2;

vector<pair<long long, long long>> vec[801];

long long dijkstra(int start, int end)
{
	long long dis[801];
	for (int i = 1; i <= N; i++) dis[i] = INF;
	priority_queue<pair<long long, long long>> pq;

	pq.push(make_pair(0, start));
	dis[start] = 0;

	while (!pq.empty()) {
		long long curTime = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			long long nextTime = vec[cur][i].second;
			int next = vec[cur][i].first;

			if (dis[next] > nextTime + curTime) {
				dis[next] = nextTime + curTime;
				pq.push(make_pair(-dis[next], next));
			}
		}
	}

	return dis[end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}

	cin >> v1 >> v2;

	long long common = dijkstra(v1, v2);
	long long route1 = dijkstra(1, v1) + dijkstra(v2, N);

	long long route2 = dijkstra(1, v2) + dijkstra(v1, N);

	long long answer = min(route1, route2);
	if (answer == INF || answer + common == INF || common == INF) cout << "-1" << '\n';
	else cout << answer + common << '\n';
}