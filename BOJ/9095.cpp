#include <iostream>
using namespace std;

int count(int num)
{
	if (num == 0)	return 1;
	else if (num < 0) return 0;
	return count(num - 1) + count(num - 2) + count(num - 3);
}

int main(int N)
{
	int num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		cout << count(num) << endl;
	}
}

