#include <iostream>
using namespace std;

typedef struct counsel_work {
	int date;
	int pay;
}counsel_work;

int max_pay(int date, int N, counsel_work work[])
{
	int pay = 0, max_payment = 0;
	int next_work = date + work[date].date;
	if (date > N - 1 || next_work > N)	return 0;
	for (int i = next_work; i <= N; i++) {
		pay = work[date].pay + max_pay(i, N, work);
		if (max_payment < pay) max_payment = pay;
	}
	return max_payment;
}

int main(int N)
{
	int payment, max_payment = 0;
	counsel_work	work[15] = { 0,0 };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> work[i].date >> work[i].pay;
	}

	for (int i = 0; i < N; i++) {
		payment = max_pay(i, N, work);
		if (max_payment < payment) max_payment = payment;
	}
	cout << max_payment;
}