#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> ex(N);
	for (int i = 0; i < N; i++) {
		cin >> ex[i];
	}

	int idx = N - 1;

	while (idx > 0 && ex[idx - 1] >= ex[idx])
		idx--;

	if (idx == 0)
	{
		cout << -1;
		return 0;
	}

	int idx2 = N - 1;

	while (idx2 >= idx && ex[idx - 1] >= ex[idx2])
		idx2--;

	swap(ex[idx - 1], ex[idx2]);
	idx2 = N - 1;

	while (idx < idx2)
	{
		swap(ex[idx], ex[idx2]);
		idx++;
		idx2--;
	}

	for (int i = 0; i < N; i++) {
		cout << ex[i] << ' ';
	}
}

/*
* Backtracking 하기에는 시간이 너무 많이 걸린다.
* 규칙 찾는 것이 중요!
*/