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

int N;
vector<int> time;
int dp[1001];
int answer = 0;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		time.push_back(t);
	}

	sort(time.begin(), time.end());

	dp[0] = time[0];
	answer = dp[0];
	for (int i = 1; i < time.size(); i++) {
		dp[i] = dp[i - 1] + time[i];
		answer += dp[i];
	}

	cout << answer << endl;
}