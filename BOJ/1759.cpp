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

int L, C;
bool exist[16] = { 0, };
vector<char> password_ch;
string password;

bool check(string password)
{
	bool issort = true;

	int aeiou = 0, alpha = 0;
	for (int i = 0; i < password.length(); i++) {
		if (i + 1 <= password.length() - 1)
		{
			if (password[i] > password[i + 1])
				issort = false;
		}

		if (password[i] == 'a' ||
			password[i] == 'e' ||
			password[i] == 'i' ||
			password[i] == 'o' ||
			password[i] == 'u')
			aeiou++;
		else {
			alpha++;
		}
	}

	if (aeiou >= 1 && alpha >= 2 && issort == true)
		return true;
	else return false;
}

void DFS(int length, int idx)
{
	if (length == L) {
		// 최소 1개의 모음 + 최소 2개의 자음
		// 오름차순
		if (check(password)) {
			cout << password << endl;
			return;
		}
	}

	for (int i = idx; i < C; i++) {
		if (exist[i] == true) continue;
		if (!password.empty() && password.back() > password_ch[i]) continue;
		exist[i] = true;
		password += password_ch[i];
		DFS(length + 1, idx);
		password.erase(length);
		exist[i] = false;
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		password_ch.push_back(c);
	}

	sort(password_ch.begin(), password_ch.end());
	// 완전탐색
	DFS(0, 0);

	return 0;
}