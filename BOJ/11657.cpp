#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999
int N,M;
long long dist[501];
vector<pair<pair<int, int>, int>> Edge;

void BelmanFord()
{
	dist[1] = 0;
	for (int i = 0; i <= N - 1; i++)
	{
		for (int j = 0; j < Edge.size(); j++) {
			int from = Edge[j].first.first;
			int to = Edge[j].first.second;
			int cost = Edge[j].second;


			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < Edge.size(); i++) {
		int from = Edge[i].first.first;
		int to = Edge[i].first.second;
		int cost = Edge[i].second;

		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dist[i] = INF;
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		Edge.push_back(make_pair(make_pair(a, b), c));
	}

	BelmanFord();

}