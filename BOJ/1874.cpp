#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define MAX_SIZE 100001


int main(int N)
{
	stack<int> s;
	int arr[MAX_SIZE] = { 0, };
	char op[MAX_SIZE * 2] = { NULL };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int idx = 0, cnt = 1, op_cnt = 0, possible = 0;

	while (1) {
		if (s.empty() || s.top() < arr[idx]) {
			s.push(cnt++);
			op[op_cnt++] = '+';
		}
		else if (s.top() == arr[idx]) {
			s.pop();
			op[op_cnt++] = '-';
			if ((++idx) == N) { possible = 1;  break; }

		}
		else {
			cout << "NO" << '\n';
			exit(0);
		}
	}

	for (int i = 0; i < op_cnt; i++)
		cout << op[i] << '\n';

	return 0;
}