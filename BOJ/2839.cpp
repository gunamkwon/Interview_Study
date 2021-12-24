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

int main()
{
	cin >> N;
	int ans = 0;

	while (N >= 0) {
		if (N % 5 == 0) {
			ans += (N / 5);
			cout << ans << endl;
			return 0;
		}
		N -= 3;
		ans++;
	}
	cout << -1 << endl;

}