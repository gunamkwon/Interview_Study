#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
using namespace std;


int main()
{
	int N, K;
	queue<int> q;
	vector<int> answer;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < K; i++) {
			if (i == K - 1) {
				answer.push_back(q.front());
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}	
	}

	cout << '<';
	for (int i = 0; i < answer.size(); i++) {
		
		if (i == answer.size() - 1) {
			cout << answer[i];
			continue;
		}
		cout << answer[i];
		cout << ", ";
	}
	cout << '>';
}
