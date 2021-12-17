#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() 
{
	int N, K;

	cin >> N >> K;
	queue<int> q;
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}

	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int temp = q.front();
		q.pop();
		if (cnt == K) {
			answer.push_back(temp);
			cnt = 0;
		}
		else {
			q.push(temp);
		}
		
	}
	
	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << answer[i];
		else cout << answer[i] << ", ";
	}
	cout << ">";
}