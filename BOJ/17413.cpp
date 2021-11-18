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
			// stack pop하면서 answer 추가	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}

			break;
		}

		// string 끝 or '<' 나오면 
		if (s[i] == '<') {

			// stack pop하면서 answer 추가	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}

			// s가 '<'이면 '>'나올때가지 그냥 추가
			while (s[i] != '>') {
				answer += s[i];
				i++;
			}
			answer += s[i];
		}
		else if (s[i] == ' ') {
			// stack pop하면서 answer 추가	
			while (!st.empty()) {
				answer += st.top();
				st.pop();
			}
			answer += ' ';
		}
		// 아니면 stack쌓기
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