#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

char alpha[5] = { 'A','E','I','O','U' };
int cnt = 0;
void DFS(string word, string cur, int& answer)
{
    if (word == cur) {
        answer = cnt;
        return;
    }
    if (cur.length() >= 5) return;

    for (int i = 0; i < 5; i++) {
        cur += alpha[i];
        cnt++;
        DFS(word, cur, answer);
        cur.erase(cur.end() - 1);
    }
}

int solution(string word) {
    int answer = 0;
    DFS(word, "", answer);
    return answer;
}

int main()
{
    cout << solution("AAAUE") << endl;
}


// 참고할만한 풀이
//int solution(string word) {
//    string v = string("AEIOU");
//    int a = word.size();
//
//    for (int i = 0, b = 1; i < word.size(); i++, b *= 5) {
//        int num = v.rfind(word[i]);
//        a += num * 781 / b;
//    }
//        
//    return a;
//}