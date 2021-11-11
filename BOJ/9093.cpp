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
	stack<char> s;
	char c;
	int N;
	cin >> N;
	scanf("%c", &c);
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		for (int l = 0; l <= str.length(); l++) {
			if (str[l] == ' ' || l == str.length()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else {
				s.push(str[l]);
			}
		}
		cout << '\n';
	}
}