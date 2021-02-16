#include <iostream>

using namespace std;

int N;
int dif = 99999999;
int arr[21][21];
int stat_t[21][21];
bool checked[21];

void backtrack(int idx, int cnt)
{
	//base case
	if (cnt == N / 2)
	{
		int start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			if (checked[i]) {
				for (int j = i + 1; j < N; j++) {
					if (checked[j])
						start += stat_t[i][j] + stat_t[j][i];
				}
			}
			else {
				for (int j = i + 1; j < N; j++) {
					if (!checked[j])
						link += stat_t[i][j] + stat_t[j][i];
				}
			}
		}
		if (abs(start - link) < dif) dif = abs(start - link);
		return;
	}
	//recursion
	for (int i = idx; i < N; i++) {
		checked[i] = 1;
		backtrack(i + 1, cnt + 1);
		checked[i] = 0;
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> stat_t[i][j];
	}

	backtrack(0, 0);

	cout << dif;

}

