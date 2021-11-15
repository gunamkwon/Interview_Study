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

#define MOD 1000000009
int T, N;
int sum_cnt;
long long dp[100001][3] = { 0, };


long long solution(int N)
{
	for (int n = 4; n <= N; n++) {
		dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % MOD;
		dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % MOD;
		dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % MOD;
	}

	return (dp[N][1] + dp[N][2] + dp[N][3]) % MOD;
}

int main()
{
	cin >> T;

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		
		cout << solution(N) << endl;
	
	}
}