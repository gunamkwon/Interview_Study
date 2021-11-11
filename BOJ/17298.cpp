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

int A[1000000], answer[1000000] = { 0, };

int main()
{
	stack<pair<int, int>> s;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (s.empty() || s.top().first >= A[i])
			s.push(make_pair(A[i], i));
		else if (s.top().first < A[i]) {
			while (!s.empty() && s.top().first < A[i]) {
				answer[s.top().second] = A[i];
				s.pop();
			}
			s.push(make_pair(A[i], i));
		}
	}
	while (!s.empty()) {
		answer[s.top().second] = -1;
		s.pop();
	}
	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
}

