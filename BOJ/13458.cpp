#include <iostream>
#include <vector>
using namespace std;

int main(int N, int B, int C)
{
	long long people = 0;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < A.size(); i++)
		cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] - B < 0) people++;
		else {
			people++;
			people += (A[i] - B) / C;
			if ((A[i] - B) % C != 0) people++;
		}
	}
	cout << people;
}

/*
* �Ѱ������� Ŀ���� �� �ִ� ���� ������ ������ ���� ��츦 ��� ����!
*/