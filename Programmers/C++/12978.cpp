#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 99999999
vector<pair<int,int>> map[51];

int Dijkstra(int start,int N, int K)
{
    int answer = 0;
    vector<int> distance(N+1, INF);
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;

    while (!pq.empty()) {
        int curDis = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < map[cur].size(); i++) {
            int nextDis = map[cur][i].second;
            int next = map[cur][i].first;

            if (distance[next] > nextDis + curDis) {
                distance[next] = nextDis + curDis;
                pq.push(make_pair(-distance[next], next));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << i << ": "<<distance[i] << endl;
        if (distance[i] <= K) {       
            answer++;
        }
    }

    return answer;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++) {
        int from = road[i][0];
        int to = road[i][1];
        int dis = road[i][2];
        
        map[from].push_back(make_pair(to, dis));
        map[to].push_back(make_pair(from, dis));
    }

    answer = Dijkstra(1,N,K);

    return answer;
}