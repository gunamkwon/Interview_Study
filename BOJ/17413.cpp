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


int num_cnt[100001] = { 0, };

string solution(string s) {
	string answer;
	stack<char> st;
	for (int i = 0; i <= s.length(); i++) {

		if (i == s.length()) {
			// stack pop�ϸ鼭 answer �߰�	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}

			break;
		}

		// string �� or '<' ������ 
		if (s[i] == '<') {

			// stack pop�ϸ鼭 answer �߰�	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}

			// s�� '<'�̸� '>'���ö����� �׳� �߰�
			while (s[i] != '>') {
				answer += s[i];
				i++;
			}
			answer += s[i];
		}
		else if (s[i] == ' ') {
			// stack pop�ϸ鼭 answer �߰�	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}
			answer += ' ';
		}
		// �ƴϸ� stack�ױ�
		else {

			st.push(s[i]);
		}

	}

	return answer;
}

int main()
{
	string str;
	getline(cin, str);
	cout << solution(str) << endl;
	return 0;
}