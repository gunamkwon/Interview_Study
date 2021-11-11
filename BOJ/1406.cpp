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


int main()
{
	string str;
	stack<char> before_cursor, after_cursor;
	int n;

	cin >> str;
	cin >> n;
	for (int i = 0; i < str.length(); i++) {
		before_cursor.push(str[i]);
	}

	for (int i = 0; i < n; i++) {
		char cmd, ch;
		cin >> cmd;

		if (cmd == 'P')
		{
			cin >> ch;
			before_cursor.push(ch);
		}

		else if (cmd == 'L') {
			if (before_cursor.empty()) continue;
			else {
				after_cursor.push(before_cursor.top());
				before_cursor.pop();
			}
		}
		else if (cmd == 'D') {
			if (after_cursor.empty()) continue;
			else {
				before_cursor.push(after_cursor.top());
				after_cursor.pop();
			}
		}
		else if (cmd == 'B') {
			if (before_cursor.empty()) continue;
			else
				before_cursor.pop();

		}
	}

	while (!before_cursor.empty()) {
		after_cursor.push(before_cursor.top());
		before_cursor.pop();
	}

	string answer;
	while (!after_cursor.empty()) {
		answer += after_cursor.top();
		after_cursor.pop();
	}

	cout << answer;
}
