#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;


pair<string, string> divide(string p) {
    int cnt1 = 0, cnt2 = 0;
    int div_idx;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') cnt1++;
        else cnt2++;

        if (cnt1 == cnt2) {
            div_idx = i;
            break;
        }
    }

    string str1 = p.substr(0, div_idx + 1);
    string str2 = p.substr(div_idx + 1, p.length());

    return make_pair(str1, str2);
}

bool check(string str) {
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        if (st.empty()) {
            if (str[i] == '(') st.push(str[i]);
            else return false;
        }
        else {
            if (str[i] == '(') st.push(str[i]);
            else {
                st.pop();
            }
        }
    }

    if (!st.empty()) return false;
    else return true;
}

string reverse(string str) {
    string ret;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') ret += ')';
        else ret += '(';
    }

    return ret;
}

string solution(string p) {
    string answer = "";

    // 1단계
    if (p == "") return p;

    // 2단계
    pair<string, string> str = divide(p);

    // 3단계
    if (check(str.first)) {
        answer += str.first;
        answer += solution(str.second);
    }
    // 4단계
    else {
        answer += '(';
        answer += solution(str.second);
        answer += ')';
        string rev;
        if (str.first.length() == 2) rev = "";
        else rev = str.first.substr(1, str.first.length() - 2);
        answer += reverse(rev);
    }

    return answer;
}

int main()
{
    solution("()))((()");
}

/*
#include <bits/stdc++.h>
using namespace std;

bool check(const string &a) {
    int r = 0;
    for (char ch : a) {
        if (ch == '(') ++r;
        else --r;
        if (r < 0) return false;
    }
    return r == 0;
}
string solution(string p) {
    if (p == "") return "";
    if (check(p)) return p;

    int i, t = 0;
    for (i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++t;
        else --t;
        if (t == 0) break;
    }

    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);

    if (check(u)) return u + solution(v);

    for (char &ch : u) ch = ch == '(' ? ')' : '(';
    return string("(") + solution(v) + ")" + u.substr(1, u.size() - 2);
}
*/