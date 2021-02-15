#include <iostream>
#include <vector>
using namespace std;

enum {
	PLUS=0,
	MIN,
	MUL,
	DIV
};

int max_num = -1000000000, min_num = 100000000;

void backtrack(vector<int> num,int op[],vector<int> opv)
{
	//base case
	if (opv.size() == num.size() - 1) {
		int result = num[0];
		for (int i = 0; i < opv.size(); i++) {
			switch (opv[i]) {
			case PLUS:
				result += num[i + 1];
				break;
			case MIN:
				result -= num[i + 1];
				break;
			case MUL:
				result *= num[i + 1];
				break;
			case DIV:
				result /= num[i + 1];
				break;
			}
		}
		if (result > max_num) max_num = result;
		if (result < min_num) min_num = result;
	}
	//recursion
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)	continue;
		op[i]--; opv.push_back(i);
		backtrack(num,op,opv);
		op[i]++; opv.pop_back();
	}
}

int main()
{
	int N;
	cin >> N;
	int op[4];
	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	vector<int> opv;
	backtrack(num,op,opv);

	cout << max_num << '\n' << min_num;
}