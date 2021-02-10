#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int N, vector<int> v)
{
	//base case
	if (v.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	//recursion
	for (int i = 1; i <= N; i++) {
		if (find(v.begin(), v.end(), i) != v.end()) continue; // 포함하면 skip
		v.push_back(i);
		backtrack(N, v);
		v.pop_back();
	}
}

int main(int N)
{
	cin >> N;
	vector<int> v;
	backtrack(N, v);
}